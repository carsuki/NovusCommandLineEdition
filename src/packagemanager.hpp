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
#ifndef PACKAGEMANAGER_H
#define PACKAGEMANAGER_H
#include <string>
#include <vector>
#include <fstream>
using namespace std;

/*
NOTE: If a string begins with an "exit=" it means that it is not availible. Everything after the '=' is the error message
NOTE: Spaces are VERY important because we need them to append other strings to them
*/

struct PackageManager {
	string search, install, reinstall, list, add, uninstall, autoremove, update, upgrade, upgrade_pkg, clean;
	void init(string pm);
	void customPM(string filename);
};
#endif
