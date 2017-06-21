//
// Created by kevin on 1/06/17.
//

#include "inc/MiscTool.h"

void MiscTool::checkCurrentWorkingDirectory(const char* argv0) {
	std::string pwd(argv0);
	
	unsigned long i = pwd.size();
	for (; pwd[i] != '/'; --i);
	pwd.erase(i + 1, pwd.size());
	
	if (pwd == "./")
		currentWorkingDirectory = "";
	else if (pwd == "/usr/bin/" || pwd == "/usr/local/bin/")
		currentWorkingDirectory = "/usr/share/spaceship/";
	else
		currentWorkingDirectory = pwd;
}

void MiscTool::checkCurrentWorkingDirectory(const char *argv0) const {
	std::string pwd(argv0);
	
	unsigned long i = pwd.size();
	for (; pwd[i] != '/'; --i);
	pwd.erase(i + 1, pwd.size());
	
	if (pwd == "./")
		currentWorkingDirectory = "";
	else if (pwd == "/usr/bin/" || pwd == "/usr/local/bin/")
		currentWorkingDirectory = "/usr/share/spaceship/resources/";
	else
		currentWorkingDirectory = pwd;
}

std::string MiscTool::getResourcesDirectory() { return (currentWorkingDirectory +  "resources/"); }
std::string MiscTool::getResourcesDirectory() const { return (currentWorkingDirectory + "resources/");}
