// Copyright (c) 2018-2019 Emil Engler et al.
// Distributed under the GNU GENERAL PUBLIC LICENSE Version 3, see the accompanying
// file LICENSE.txt or <https://www.gnu.org/licenses/gpl-3.0.html>.
#include <iostream>

#include <vector>

#include <string>

#include <cstring>

#include "packagemanager.hpp"

#include "utils.hpp"

// Default path for config files
string ConfigPath = "/usr/local/etc/nvs/nvs";
string CustomPath = "/usr/local/etc/nvs/custom";

//This is the default help message that gets displayed when user types the nvs help command.
const char * HelpMsg =
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

//This is the about message that gets displayed when user types the nvs about command.
const char * AboutMsg =
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
//If you consider you can add more to the syntax is very simple, start here by adding a descriptive structure, this means if your command executes "apt cow" for example, your string should be named "CowCmds"
//After that perfom the selected by adding it below in this way "cow" and "--cow".
vector < string > SearchCmds = {
  "search",
  "--search"
};
vector < string > ListCmds = {
  "list",
  "--list"
};
vector < string > InstallCmds = {
  "install",
  "--install"
};
vector < string > ReinstallCmds = {
  "reinstall",
  "--reinstall"
};
vector < string > RemoveCmds = {
  "remove",
  "--remove"
};
vector < string > AddCmds = {
  "edit-sources",
  "--edit-sources"
};
vector < string > AutoremoveCmds = {
  "autoremove",
  "--autoremove"
};
vector < string > UpgradeCmds = {
  "upgrade",
  "--upgrade"
};
vector < string > UpdateCmds = {
  "update",
  "--update"
};
vector < string > InfoCmds = {
  "info",
  "--info"
};
vector < string > upgreadableCmds = {
  "upgreadable",
  "--upgreadable"
};
vector < string > CleanCmds = {
  "clean",
  "--clean"
};
vector < string > HelpCmds = {
  "help",
  "--help"
};
vector < string > AboutCmds = {
  "about",
  "--about"
};

int main(int argc, char * argv[]) {
  vector < string > PackageManagerList = GetPackageManagerList();

  // Get the path if the user has changed it with an enviroment variable
  char * EnvConfigPath = getenv("SYSGET_CONFIG_PATH");
  char * EnvCustomPath = getenv("SYSGET_CUSTOM_PATH");

  // Check if the enviroment variables aren't empty
  if (EnvConfigPath != NULL) {
    ConfigPath = string(EnvConfigPath);
  }

  if (EnvCustomPath != NULL) {
    CustomPath = string(EnvCustomPath);
  }

  // Create a config file if the config file does not exists
  if (!file_exists(ConfigPath.c_str())) {
    cout << "Please choose a package manager: " << endl;

    for (unsigned int i = 0; i < PackageManagerList.size(); i++) {
      cout << (i + 1) << ". " << PackageManagerList[i] << endl;
    }

    cout << endl;

    // Now lets listen for the input
    string input;
    cin >> input;
    // Convert the input to an int to see if it is valid
    unsigned int InputInt;
    try {
      InputInt = stoi(input);
    } catch (exception & ) {
      cerr << "You need to enter a number" << endl;
      exit(1);
    }

    // Create config files

    // Finally check if the input is valid
    if (InputInt > PackageManagerList.size() || InputInt <= 0) {
      cerr << "Input is out of range" << endl;
      exit(1);
    }

    // We need to reduce the input by 1 because arrays start at 0
    CreateConf(ConfigPath, PackageManagerList[InputInt - 1] + "\n");

  }

  // Get the name of the package manager from the config file
  string pm_config = GetPackageManager(ConfigPath);

  if (pm_config == "ERROR") {
    cerr << "Your config is broken please restart the program to create a new one" << endl;
    if (remove(ConfigPath.c_str()) != 0) {
      cerr << "Error while deleting broken config file, are you root?" << endl;
    }
    exit(1);
  }

  // If sysget_config does not exists use defaults
  else {
    pm.init(pm_config);
  }

  // Now parse the console arguments
  // If the user enters no operation
  if (argc < 2) {
    cout << HelpMsg;
    cerr << "Error, you need an operation." << endl;
    exit(1);
  }

  // Lets set argv[1] to cmd for a more handy usage
  string cmd = argv[1];

  if (VectorContains(cmd, SearchCmds)) { //This is the "Search command and a little explanation on how it works"
    // If the user enters no search query
    if (argc < 3) { //This checks if user actually introduced a package name, if no it's going to return an erorr for the user
      cerr << "Error, no search query provided" << endl;
      exit(1);
    }
    checkcmd(pm.search);
    system(string(pm.search + argv[2]).c_str());
  }

  if (VectorContains(cmd, ListCmds)) { //This is the info command, gets info about a package and displays it to user 
    checkcmd(pm.list);
    system(pm.list.c_str());
  } else if (VectorContains(cmd, InfoCmds)) {
    // If the user enters no package to to get info from
    if (argc < 3) {
      cerr << "Error, no package to get info from was provided." << endl;
      exit(1);
    }

    for (int i = 2; i < argc; i++) {
      checkcmd(pm.info);
      execcmd = execcmd + argv[i] + " ";
    }

    system(string(pm.info + execcmd).c_str());
  } else if (VectorContains(cmd, InstallCmds)) {
    // If the user enters no package to install
    if (argc < 3) {
      cerr << "Error, no package for the installation provided" << endl;
      exit(1);
    }

    for (int i = 2; i < argc; i++) {
      checkcmd(pm.install);
      execcmd = execcmd + argv[i] + " ";
    }

    system(string(pm.install + execcmd).c_str());
  } else if (VectorContains(cmd, ReinstallCmds)) {
    // If the user enters no package to reinstall
    if (argc < 3) {
      cerr << "Error, no package for the reinstallation provided" << endl;
      exit(1);
    }

    for (int i = 2; i < argc; i++) {
      checkcmd(pm.reinstall);
      execcmd = execcmd + argv[i] + " ";
    }

    system(string(pm.reinstall + execcmd).c_str());
  }

  //If the user wants to add a repo
  else if (VectorContains(cmd, AddCmds)) {
    for (int i = 2; i < argc; i++) {
      checkcmd(pm.add);
      execcmd = execcmd + argv[i] + " ";
    }

    system(string(pm.add + execcmd).c_str());

  } else if (VectorContains(cmd, RemoveCmds)) {
    // If the user enters no package to remove
    if (argc < 3) {
      cerr << "Error, no package for the removal provided" << endl;
      exit(1);
    }

    for (int i = 2; i < argc; i++) {
      checkcmd(pm.uninstall);
      execcmd = execcmd + argv[i] + " ";
    }

    system(string(pm.uninstall + execcmd).c_str());
  }

  // FYI: checkcmd will check if your package manager supports this feature

  // Autoremove will remove orpahns
  else if (VectorContains(cmd, AutoremoveCmds)) {
    checkcmd(pm.autoremove);
    system(pm.autoremove.c_str());
  }

  // Upgrading will not update the database
  else if (VectorContains(cmd, UpgradeCmds)) {
    if (argc < 3) {
      checkcmd(pm.upgrade);
      system(pm.upgrade.c_str());
    }

    // Upgrade specifc package
    else {
      for (int i = 2; i < argc; i++) {
        checkcmd(pm.upgrade_pkg);
        execcmd = execcmd + argv[i] + " ";
      }

      system(string(pm.upgrade_pkg + execcmd).c_str());
    }
  }

  // Clean will clean the download cache
  else if (VectorContains(cmd, CleanCmds)) {
    checkcmd(pm.clean);
    system(pm.clean.c_str());
  }

  // Update will only refresh the database		
  else if (VectorContains(cmd, UpdateCmds)) {
    checkcmd(pm.update);
    system(pm.update.c_str());
  }

  // Help
  else if (VectorContains(cmd, HelpCmds)) {
    cout << HelpMsg;
  }

  // About
  else if (VectorContains(cmd, AboutCmds)) {
    cout << AboutMsg;
  } else {
    cerr << "Unknown operation '" << cmd << "'. Try nvs help" << endl;
    exit(1);
  }
}