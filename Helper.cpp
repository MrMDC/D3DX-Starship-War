#include "Helper.h"

double Helper::remapRange(double number, double lowerA, double upperA, double lowerB, double upperB)
{
    double temp;

	if (lowerA > upperA) {
		temp = upperA;
		upperA = lowerA;
		lowerA = temp;
	}

	if (number >= upperA || number <= lowerA) return number;

	if (lowerB > upperB) {
		temp = upperB;
		upperB = lowerB;
		lowerB = temp;
	}

	temp = (number - lowerA) / (upperA - lowerA) * (upperB - lowerB) + lowerB;

	return temp;
}
