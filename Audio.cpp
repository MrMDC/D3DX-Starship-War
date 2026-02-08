#include "Audio.h"

Audio::Audio()
{
}

Audio::~Audio()
{
	cleanup();
}

void Audio::init(float volume, int frequency, int audioType)
{
	//Initialize variables
	this->volume = volume;
	this->frequency = frequency;
	this->audioType = audioType;
}

int Audio::getAudioType()
{
	return audioType;
}

float Audio::getVolume()
{
	return volume;
}

float Audio::getFrequency()
{
	return frequency;
}

Sound* Audio::getAudio()
{
	return audio;
}

Channel* Audio::getChannel()
{
	return channel;
}

void Audio::setAudioType(int audioType)
{
	this->audioType = audioType;
}

void Audio::setVolume(float volume)
{
	this->volume = volume;
}

void Audio::setFrequency(int frequency)
{
	this->frequency = frequency;
}

void Audio::setAudio(Sound* audio)
{
	this->audio = audio;
}

void Audio::setChannel(Channel* channel)
{
	this->channel = channel;
}

void Audio::cleanup()
{
	//Cleanup the channel and audio resources
	if (channel != NULL) {
		channel = NULL;
	}

	if (audio != NULL) {
		audio->release();
		audio = NULL;
	}
}
