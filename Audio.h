#pragma once
#ifndef AUDIO_H
#define AUDIO_H

#include "fmod.hpp"
#include "BasicHeader.h"

using namespace FMOD;

class Audio
{
protected:
	Sound* audio = NULL;
	Channel* channel = NULL;
	int audioType;
	float volume;
	int frequency;

public:
	Audio();
	~Audio();

	void init(float volume, int frequency, int audioType);

	int getAudioType();
	float getVolume();
	float getFrequency();
	Sound* getAudio();
	Channel* getChannel();

	void setAudioType(int audioType);
	void setVolume(float volume);
	void setFrequency(int frequency);
	void setAudio(Sound* audio);
	void setChannel(Channel* channel);

	void cleanup();
};

#endif