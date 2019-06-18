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
#include "utils.hpp"

bool file_exists(const char *filename) {
	ifstream file(filename);
	return (bool)file;
}

//This helps the const char you saw at the start of the file
vector<string> GetPackageManagerList() {
	vector<string> PackageManagerList = { "apt"};
	return PackageManagerList;
}

// Check will check if the string contains an exit message
void checkcmd(string cmd) {
	size_t errorfind = cmd.find("exit=");
	if(errorfind != string::npos) {
		string errormsg = cmd.substr(5);
		cerr << errormsg << endl;
		exit(1);
	}
}
// Check if an item exists in a vector
bool VectorContains(string s, vector<string> v) {
	return std::find(v.begin(), v.end(), s) != v.end();
}
