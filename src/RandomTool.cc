//
// Created by kevin on 1/06/17.
//

#include "inc/RandomTool.h"

int Random::generateRandomInt(int start, int end) {
	std::random_device randomDevice;
	std::mt19937 eng(randomDevice());
	std::uniform_int_distribution<> distribution(start, end);
	return distribution(eng);
}
