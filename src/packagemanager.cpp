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
		uninstall = "sudo apt-get purge ";
		autoremove = "sudo apt-get purge --autoremove";
		update = "sudo apt-get update";
		upgrade = "sudo apt-get upgrade";
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
