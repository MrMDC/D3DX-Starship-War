#pragma once
#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include "fmod.hpp"
#include "Audio.h"

enum AudioType {
	bgm, effect
};

enum AudioList {
	background_audio, click_audio, explosion, win, game_over
};

class AudioManager
{
protected:
	System* system = NULL;
	Channel* channel = NULL;
	FMOD_RESULT fresult;

	ChannelGroup* masterGrp = NULL;
	ChannelGroup* bgmGrp = NULL;
	ChannelGroup* effectGrp = NULL;

	vector<Audio*> audioList;

	float bgmVolume;
	float effectVolume;

	void init();
	ChannelGroup* checkChannelGroup(int audioType);

public:
	void playAudio(int audio);
	void loadAudio(const char* address, boolean loopable);
	void update();

	ChannelGroup* getMasterGrp();
	ChannelGroup* getBgmGrp();
	ChannelGroup* getEffectGrp();
	vector<Audio*> getAudioList();

	float getGrpVolume(int grp);
	void setGrpVolume(int grp, float volume);

	void startBgm();

	void cleanup();

	AudioManager();
	~AudioManager();
};

#endif