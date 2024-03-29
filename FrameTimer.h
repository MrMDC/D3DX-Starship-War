#pragma once
#ifndef FRAMETIMER_H
#define FRAMETIMER_H

#include <Windows.h>

class FrameTimer
{
protected:
	LARGE_INTEGER timerFreq;        // Frequency of the timer
	LARGE_INTEGER timeNow;          // Current time
	LARGE_INTEGER timePrevious;     // Time at the previous frame
	int reqFps;						// Requested frames-per-second
	float intervalsPerFrame;        // Time intervals per frame
	float intervalsSinceLastUpdate; // Time intervals since the last frame update

public:
	void init(int reqFps);
	int framesToUpdate();
	int getFPS();

	FrameTimer(int reqFps);
	~FrameTimer();
};

#endif