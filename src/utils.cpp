// Copyright (c) 2018-2019 Emil Engler et al.
// Distributed under the GNU GENERAL PUBLIC LICENSE Version 3, see the accompanying
// file LICENSE.txt or <https://www.gnu.org/licenses/gpl-3.0.html>.
#include "utils.hpp"

bool file_exists(const char *filename) {
	ifstream file(filename);
	return (bool)file;
}

vector<string> GetPackageManagerList() {
	vector<string> PackageManagerList = { "apt-get"};
	return PackageManagerList;
}

string GetPackageManager(string filename) {
	string line;
	string packagemanager;
	ifstream file(filename);

	vector<string> PackageManagerList = GetPackageManagerList();

	if(file.is_open()) {
		while(getline(file, line)) {
			// If the package manager is valid
			if(std::find(PackageManagerList.begin(), PackageManagerList.end(), line) != PackageManagerList.end()) {
				return line;
			}

			else {
				return "ERROR";
			}
		}
	}

	else {
		cout << "Unable to open config file" << endl;
		exit(1);
	}
	// clang on macOS will return a warning if a non-void function has no return
	return "ERROR";
}

void CreateConf(string filename, string packagemanager) {
	system("mkdir -p /usr/local/etc/nvs");
	ofstream file(filename);
	if(file.is_open()) {
		file << packagemanager;
	}

	else {
		cout << "Unable to assign package manager, are you root ?" << endl;
		exit(1);
	}
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
