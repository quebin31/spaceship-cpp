//
// Created by kevin on 1/06/17.
//

#include "inc/StringTool.h"


std::string StringTool::intToString(int number) const {
	std::stringstream sstr;
	sstr << number;
	std::string toString;
	sstr >> toString;
	return toString;
}

int StringTool::stringToInt(std::string number) const {
	std::stringstream sstr;
	sstr << number;
	int toInt;
	sstr >> toInt;
	return toInt;
}

