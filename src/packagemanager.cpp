// Copyright (c) 2018-2019 Emil Engler et al.
// Distributed under the GNU GENERAL PUBLIC LICENSE Version 3, see the accompanying
// file LICENSE.txt or <https://www.gnu.org/licenses/gpl-3.0.html>.
#include "packagemanager.hpp"

// This is the constructor
void PackageManager::init(string pm) {

	if(pm == "apt-get") {
		// apt-get
		add = "sudo apt edit-sources";
		search = "sudo apt-cache search ";
		install = "sudo apt-get update && sudo apt-get install ";
		reinstall = "sudo apt-get update && sudo apt-get reinstall ";
		uninstall = "sudo apt-get purge ";
		autoremove = "sudo apt-get purge --autoremove";
		upgrade = "sudo apt-get update && sudo apt-get upgrade";
		upgrade_pkg = "sudo apt-get upgrade ";
		clean = "sudo apt-get autoclean && sudo apt-get clean";
	}
}

void PackageManager::customPM(string filename) {
	ifstream file(filename);
	string line;
	vector<string> commands;
	int number_of_lines = 0;
	if(file.is_open()) {
		while(getline(file ,line)) {
			commands.push_back(line);
			number_of_lines++;
		}
	}	
}
