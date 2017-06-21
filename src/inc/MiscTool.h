//
// Created by kevin on 1/06/17.
//

#ifndef SPACESHIP_MISCTOOL_H
#define SPACESHIP_MISCTOOL_H

#include "SpaceShipIncludes.h"

class MiscTool {
private:
		std::string currentWorkingDirectory;
public:
		MiscTool() = default;
		
		void checkCurrentWorkingDirectory(const char* argv0);
		void checkCurrentWorkingDirectory(const char* argv0) const;
		
		std::string getResourcesDirectory();
		std::string getResourcesDirectory() const;
};

MiscTool Tool;

#endif //SPACESHIP_MISCTOOL_H
