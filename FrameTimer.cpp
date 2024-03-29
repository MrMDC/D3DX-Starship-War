#include "FrameTimer.h"

void FrameTimer::init(int reqFps)
{
	// Query the performance frequency and current time
	QueryPerformanceFrequency(&timerFreq);
	QueryPerformanceCounter(&timeNow);
	QueryPerformanceCounter(&timePrevious);

	// Set requested FPS, intervals per frame
	this->reqFps = reqFps;
	intervalsPerFrame = ((float)timerFreq.QuadPart / this->reqFps);
}

int FrameTimer::framesToUpdate()
{
	int framesToUpdate = 0;
	QueryPerformanceCounter(&timeNow);

	// Calculate the time interval since the last update
	intervalsSinceLastUpdate = (float)(timeNow.QuadPart - timePrevious.QuadPart);
	framesToUpdate = (int)(intervalsSinceLastUpdate / intervalsPerFrame);

	// If we are not updating any frames, keep the old previous timer count
	if (framesToUpdate != 0) {
		QueryPerformanceCounter(&timePrevious);
	}

	return framesToUpdate;
}

int FrameTimer::getFPS()
{
	return reqFps;
}

FrameTimer::FrameTimer(int reqFps)
{
	init(reqFps);
}

FrameTimer::~FrameTimer()
{
}
