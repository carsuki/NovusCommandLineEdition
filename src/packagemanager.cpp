// Copyright (c) 2018-2019 Emil Engler et al.
// Distributed under the GNU GENERAL PUBLIC LICENSE Version 3, see the accompanying
// file LICENSE.txt or <https://www.gnu.org/licenses/gpl-3.0.html>.
#include "packagemanager.hpp"

// This is the constructor
void PackageManager::init(string pm) {

	if(pm == "apt-get") {
		// apt-get
		add = "apt edit-sources";
		search = "apt-cache search ";
		install = "apt-get update && apt-get install ";
		uninstall = "apt-get purge ";
		autoremove = "apt-get purge --autoremove";
		update = "apt-get update";
		upgrade = "apt-get upgrade";
		upgrade_pkg = "apt-get upgrade ";
		clean = "apt-get autoclean && apt-get clean";
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

		if(number_of_lines != 8) {
			search = "exit=Invalid custom file";
			install = "exit=Invalid custom file";
			uninstall = "exit=Invalid custom file";
			autoremove = "exit=Invalid custom file";
			update = "exit=Invalid custom file";
			upgrade = "exit=Invalid custom file";
			upgrade_pkg = "exit=Invalid custom file";
			clean = "exit=Invalid custom file";
		}
		
		else {
			search = commands[0];
			install = commands[1];
			uninstall = commands[2];
			autoremove = commands[3];
			update = commands[4];
			upgrade = commands[5];
			upgrade_pkg = commands[6];
			clean = commands[7];
		}
	}
}
