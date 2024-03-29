#pragma once
#ifndef HELPER_H
#define HELPER_H

#include "MoreHeader.h"

class Helper
{
public:
	static double remapRange(double number, double lowerA, double upperA, double lowerB, double upperB);
};

#endif