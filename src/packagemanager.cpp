// Copyright (c) 2018-2019 Emil Engler et al.
// Distributed under the GNU GENERAL PUBLIC LICENSE Version 3, see the accompanying
// file LICENSE.txt or <https://www.gnu.org/licenses/gpl-3.0.html>.
#include "packagemanager.hpp"

// This is the constructor
void PackageManager::init(string pm) {

	if(pm == "apt") {
		// apt
		search = "sudo apt search ";
		install = "sudo apt update && sudo apt install ";
		uninstall = "sudo apt purge ";
		autoremove = "sudo apt purge --autoremove";
		update = "sudo apt update";
		upgrade = "sudo apt update && sudo apt upgrade";
		upgrade_pkg = "sudo apt upgrade ";
		clean = "sudo apt autoclean && sudo apt clean";
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
