#include "AudioManager.h"

void AudioManager::init()
{
	//Initialize the sound manager
	fresult = FMOD::System_Create(&system);
	if (fresult != 0) return;
	fresult = system->init(32, FMOD_INIT_NORMAL, 0);
	if (fresult != 0) return;
	fresult = system->getMasterChannelGroup(&masterGrp);
	if (fresult != 0) return;
	fresult = system->createChannelGroup("BGM", &bgmGrp);
	if (fresult != 0) return;
	fresult = system->createChannelGroup("SFX", &effectGrp);
	if (fresult != 0) return;

	//Set the default volume size
	bgmVolume = 1.0f;
	effectVolume = 1.0f;

	//Initialize all audios to its respective enum member
	loadAudio("Assets/Audio/bgm1.mp3", true);
	audioList.at(background_audio)->init(1.0f, 96000, bgm);

	loadAudio("Assets/Audio/click.mp3", false);
	audioList.at(click_audio)->init(0.7f, 48000, effect);

	loadAudio("Assets/Audio/explode.mp3", false);
	audioList.at(explosion)->init(0.7f, 48000, effect);

	loadAudio("Assets/Audio/win.mp3", false);
	audioList.at(win)->init(0.7f, 48000, effect);

	loadAudio("Assets/Audio/game_over.mp3", false);
	audioList.at(game_over)->init(0.7f, 48000, bgm);
}

ChannelGroup* AudioManager::checkChannelGroup(int audioType)
{
	//Check which type of channel were loaded
	if (audioType == bgm) {
		return bgmGrp;
	}
	else if (audioType == effect) {
		return effectGrp;
	}

	return nullptr;
}

void AudioManager::playAudio(int audio)
{
	int channelGrp = audioList.at(audio)->getAudioType();
	
	//Play the audio
	fresult = system->playSound(audioList.at(audio)->getAudio(), checkChannelGroup(channelGrp), true, &channel);
	channel->setVolume(audioList.at(audio)->getVolume());
	channel->setFrequency(audioList.at(audio)->getFrequency());

	checkChannelGroup(channelGrp)->setVolume(getGrpVolume(channelGrp));
	audioList.at(audio)->setChannel(channel);
	channel->setPaused(false);
}

void AudioManager::loadAudio(const char* address, boolean loopable)
{
	Audio* audio = new Audio();
	Sound* sound = nullptr;

	//Load the audio out to play it
	fresult = system->createSound(address, FMOD_DEFAULT, 0, &sound);
	if (loopable) {
		fresult = sound->setMode(FMOD_LOOP_NORMAL);
	}
	else {
		fresult = sound->setMode(FMOD_LOOP_OFF);
	}

	//Push the audio item into a list
	audio->setAudio(sound);
	audioList.push_back(audio);
}

void AudioManager::update()
{
	system->update();
}

ChannelGroup* AudioManager::getMasterGrp()
{
	return masterGrp;
}

ChannelGroup* AudioManager::getBgmGrp()
{
	return bgmGrp;
}

ChannelGroup* AudioManager::getEffectGrp()
{
	return effectGrp;
}

vector<Audio*> AudioManager::getAudioList()
{
	return audioList;
}

float AudioManager::getGrpVolume(int grp)
{
	if (grp == bgm) {
		return bgmVolume;
	}
	else if (grp == effect) {
		return effectVolume;
	}

	return 0.0f;
}

void AudioManager::setGrpVolume(int grp, float volume)
{
	switch (grp) {
	case bgm:
		bgmVolume = volume;
		break;
	case effect:
		effectVolume = volume;
		break;
	}
	checkChannelGroup(grp)->setVolume(getGrpVolume(grp));
}

void AudioManager::startBgm()
{
	playAudio(background_audio);
}

void AudioManager::cleanup()
{
	if (channel != NULL) {
		channel = NULL;
	}

	//Cleanup all the audio saved to the list
	int vectorSize;

	vectorSize = audioList.size();
	for (int i = 0; i < vectorSize; i++) {
		audioList.at(audioList.size() - 1)->cleanup();
		audioList.pop_back();
	}

	if (bgmGrp != NULL) {
		bgmGrp->release();
		bgmGrp = NULL;
	}

	if (effectGrp != NULL) {
		effectGrp->release();
		effectGrp = NULL;
	}

	if (masterGrp != NULL) {
		masterGrp->release();
		masterGrp = NULL;
	}

	if (system != NULL) {
		system->release();
		system = NULL;
	}
}

AudioManager::AudioManager()
{
	init();
}

AudioManager::~AudioManager()
{
	cleanup();
}
