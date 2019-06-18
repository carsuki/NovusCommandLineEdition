//Copyright (c) 2019 Polar Team
//Modifications Copyright (c) 2019 Polar Team

//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.

// Copyright (c) 2018-2019 Emil Engler et al.
// Distributed under the GNU GENERAL PUBLIC LICENSE Version 3, see the accompanying
// file LICENSE or <https://www.gnu.org/licenses/gpl-3.0.html>.
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include "packagemanager.hpp"
#include "utils.hpp"

const char *pm = "apt";
const char *pm_config = "apt";

const char *HelpMsg =
	"Novus CLI Help\n"
	"nvs [command] <query>\n"
	"\n"
	"search [query]\t\t\tSearches for a package in your resporitories\n"
    "list\t\t\t\tLists all packages in your resporitories\n"
	"install [package]\t\tInstalls a package\n"
	"reinstall [package]\t\tReinstalls a package\n"
	"remove [package]\t\tRemoves a package\n"
	"edit-sources\t\t\tOpens the APT repo editor\n"
	"autoremove\t\t\tRemoves unneeded packages (orphans)\n"
	"update\t\t\t\tUpdate the repo lists\n"		
	"upgrade\t\t\t\tUpgrade all packages\n"
	"clean\t\t\t\tClear the download cache\n"
	"help\t\t\t\tOpen this help page\n"
	"about\t\t\t\tView legal information\n\n";

const char *AboutMsg =
	"About Novus CLI\n"
	"Copyright (C) 2019 Polar Development.\n"
	"http://randomlink.com\n"
	"\n"
	"This program is free software: you can redistribute it and/or modify\n"
	"it under the terms of the GNU General Public License as published by\n"
	"the Free Software Foundation, either version 3 of the License, or\n"
	"(at your option) any later version.\n"
	"\n"
	"This program is distributed in the hope that it will be useful,\n"
	"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
	"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
	"GNU General Public License for more details.\n"
	"\n"
	"You should have received a copy of the GNU General Public License\n"
	"along with this program.  If not, see <http://www.gnu.org/licenses/>.\n"
	"\n"
	"Novus CLI is made possible by the following software: \n"
	"\n"
	"APT & APT-get by Debian: https://packages.debian.org/stretch/apt"
	"\n"
	"Sysget by Emil Engler: http://sysget.emilengler.com"
	"\n"
	"Project Serna by Diego Magdaleno & Diatrus: https://sernarepo.com/";


// Default syntax operations
vector<string> SearchCmds = {"search", "--search"}; //Search a package 
vector<string> ListCmds = {"list", "--list"}; //List the packages 
vector<string> InstallCmds = {"install", "--install"}; //Install Packages
vector<string> ReinstallCmds = {"reinstall", "--reinstall"}; //Reinstalls packages
vector<string> RemoveCmds = {"remove", "--remove"}; //Removes the packages 
vector<string> AddCmds= {"edit-sources", "--edit-sources"}; //Allows user to edit sources
vector<string> AutoremoveCmds = {"autoremove", "--autoremove"}; //Removes orphan packages 
vector<string> UpgradeCmds = {"upgrade", "--upgrade"}; //Upgrades selected packages
vector<string> UpdateCmds = {"update", "--update"};	//Updates the data base
vector<string> CleanCmds = {"clean", "--clean"}; //Cleans packages
vector<string> HelpCmds = {"help", "--help"}; //Dislays help 
vector<string> AboutCmds = {"about", "--about"}; //Displays legal stuff 

int main(int argc, char* argv[]) {
	vector<string> PackageManagerList = GetPackageManagerList();

	//Inititializaes the package manager
	PackageManager pm;
	string execcmd;	// Will be appended with packages
	pm.init(pm_config);

	// Now parse the console arguments
	// If the user enters no operation
	if(argc < 2) {
        cout << HelpMsg;
        cerr << "Error, you need an operation." << endl;
		exit(1);
	}

	// Lets set argv[1] to cmd for a more handy usage
	string cmd = argv[1];

    //This is the search checks it does in order to perform the search action.
	
	if(VectorContains(cmd, SearchCmds)) {
		// If the user enters no search query
		if(argc < 3) {
			cerr << "Error, no search query provided" << endl;
			exit(1);
		}
		checkcmd(pm.search);
		system(string(pm.search + argv[2]).c_str());
	}
    
    //This is the list command, lists all packages for the user, as you can see there are not checks here

    if(VectorContains(cmd, ListCmds)) {
        checkcmd(pm.list);
        system(pm.list.c_str());
    }

     //This is the install checks to see if user search package is valid

	else if(VectorContains(cmd, InstallCmds)) {
		// If the user enters no package to install
		if(argc < 3) {
			cerr << "Error, no package for the installation provided" << endl;
			exit(1);
		}

		for(int i = 2; i < argc; i++) {
			checkcmd(pm.install);
			execcmd = execcmd + argv[i] + " ";
		}

		system(string(pm.install + execcmd).c_str());
	}
    
    //This is the reinstall checks to see if user search package is valid
    else if(VectorContains(cmd, ReinstallCmds)) {
        // If the user enters no package to reinstall
        if(argc < 3) {
            cerr << "Error, no package for the reinstallation provided" << endl;
            exit(1);
        }
        
        for(int i = 2; i < argc; i++) {
            checkcmd(pm.reinstall);
            execcmd = execcmd + argv[i] + " ";
        }
        
        system(string(pm.reinstall + execcmd).c_str());
    }

	//This is the edit-sources command/addd command, if the user wants to add a repo
	else if(VectorContains(cmd, AddCmds)) {
		for(int i = 2; i < argc; i++) {
			checkcmd(pm.add);
			execcmd = execcmd + argv[i] + " ";
		}

		system(string(pm.add + execcmd).c_str());
		
	}

	//This is the remove checks to see if user search package is valid
	else if(VectorContains(cmd, RemoveCmds)) {
		// If the user enters no package to remove
		if(argc < 3) {
			cerr << "Error, no package for the removal provided" << endl;
			exit(1);
		}

		for(int i = 2; i < argc; i++) {
			checkcmd(pm.uninstall);
			execcmd = execcmd + argv[i] + " ";
		}

		system(string(pm.uninstall + execcmd).c_str());
	}

	// FYI: checkcmd will check if your package manager supports this feature

	// Autoremove will remove orpahns
	else if(VectorContains(cmd, AutoremoveCmds)) {
		checkcmd(pm.autoremove);
		system(pm.autoremove.c_str());
	}

	// Upgrading will not update the database
	else if(VectorContains(cmd, UpgradeCmds)) {
		if(argc < 3) {
			checkcmd(pm.upgrade);
			system(pm.upgrade.c_str());
		}

		// Upgrade specifc package
		else {
			for(int i = 2; i < argc; i++) {
				checkcmd(pm.upgrade_pkg);
				execcmd = execcmd + argv[i] + " ";
			}

			system(string(pm.upgrade_pkg + execcmd).c_str());
		}
	}

	// Clean will clean the download cache
	else if(VectorContains(cmd, CleanCmds)) {
		checkcmd(pm.clean);
		system(pm.clean.c_str());
	}

	
    // Update will only refresh the database		
 	else if(VectorContains(cmd, UpdateCmds)) {		
 		checkcmd(pm.update);		
 		system(pm.update.c_str());		
 	}		


	// Help
	else if(VectorContains(cmd, HelpCmds)) {
		cout << HelpMsg;
	}

	// About
	else if(VectorContains(cmd, AboutCmds)) {
		cout << AboutMsg;
	}

	//In case user enters a undeclared operation
	else {
		cerr << "Unknown operation '" << cmd << "'. Try nvs help" << endl;
		exit(1);
	}
}
