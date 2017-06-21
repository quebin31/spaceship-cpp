//
// Created by kevin on 5/06/17.
//

#include "inc/ScoreInterface.h"

Score::Score() : score(0) {}

Score *Score::get() {
	if (!Score::instance)
		Score::instance = new Score;
	return Score::instance;
}

void Score::del() {
	delete instance;
}

std::string Score::getScore() {
	return String::intToString(score);
}

void Score::setScore(int score) {
	this->score = score;
}

void Score::incScore(int value) {
	this->score += value;
}

void Score::decScore(int value) {
	this->score -= value;
}
