// Copyright (c) 2018-2019 Emil Engler et al.
// Distributed under the GNU GENERAL PUBLIC LICENSE Version 3, see the accompanying
// file LICENSE.txt or <https://www.gnu.org/licenses/gpl-3.0.html>.
#include "packagemanager.hpp"

// This is the constructor
void PackageManager::init(string pm) {

	if(pm == "apt") {
		// apt
		search = "sudo apt search ";
        list = "apt list";
		install = "sudo apt update && sudo apt install ";
        reinstall = "sudo apt update && sudo apt reinstall ";
		uninstall = "sudo apt purge ";
		autoremove = "sudo apt purge --autoremove";
		update = "sudo apt update";
		upgrade = "sudo apt update && sudo apt upgrade";
		upgrade_pkg = "sudo apt upgrade ";
        add = "sudo apt edit-sources ";
		clean = "sudo apt autoclean && sudo apt clean";
	}
}