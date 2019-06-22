<p align="center">
  <a href="" rel="noopener">
 <img width=200px height=200px src="https://i.imgur.com/6wj0hh6.jpg" alt="Project logo"></a>
</p>

<h3 align="center">Novus Command Line Edition.</h3>

<div align="center">

  [![Status](https://img.shields.io/badge/status-active-success.svg)]() 
  [![GitHub Issues](https://img.shields.io/github/issues/kylelobo/The-Documentation-Compendium.svg)](https://github.com/kylelobo/The-Documentation-Compendium/issues)
  [![GitHub Pull Requests](https://img.shields.io/github/issues-pr/kylelobo/The-Documentation-Compendium.svg)](https://github.com/kylelobo/The-Documentation-Compendium/pulls)
  [![License](https://img.shields.io/github/license/DiegoMagdaIeno/NovusCommnadLineEdition.svg?style=flat-square)](/LICENSE)

</div>

---

<p align="center"> The best APT front-end for macOS (Or Linux)
    <br> 
</p>

## 📝 Table of Contents
- [About](#about)
- [Getting Started](#getting_started)
- [Usage](#usage)
- [Built Using](#built_using)
- [Contributing](../CONTRIBUTING.md)
- [Authors](#authors)
- [Acknowledgments](#acknowledgement)

## 🧐 About <a name = "about"></a>
NovusCLI is a lite version of the full Novus package manager (Coming later this year) that allows users to start with a simple syntax, for their favorite APT package manager.

## 🏁 Getting Started <a name = "getting_started"></a>
Getting started for contributing to NovusCLI is very easy, you just need to follow the instructions below if you wish to build from source.

### Prerequisites
In order to start building NovusCLI, you are going to need to have Apple's developer tools installed or xcode for example. You can get those [here](https://developer.apple.com/xcode/).

NovusCLI uses default Apple clang compiler so this is all you need, but getting MacPT is higly recommended.

### Installing

For installation NovusCLI makes it really easy:

* cd into the directory
* Run make 
* Run sudo make install
* Enjoy Novus commnad line edition!

This are all the steps that you need to follow to get NovusCLI running on your system!

## 🎈 Usage <a name="usage"></a>
NovusCLI has a memorable set of commands that will allow you to use it everyday as your syntax for MacPT:

* ```nvs search [query]``` - Searches for a package in your resporitories
* ```list```  - Lists all packages in your resporitories
* ```nvs install [package]``` - Installs a package 
* ```reinstall [package]``` - Reinstalls a package
* ``` remove [package]``` - Removes a package
* ```edit-sources``` - Opens the APT repo editor
* ```autoremove``` - Removes unneeded packages (orphans)
* ```update``` - Update the repo lists
* ```upgrade``` - Upgrade all packages
* ```clean``` - Clear the download cache
* ```help``` - Open a help page similar to this one
* ```about``` - View legal information

Using NovusCLI is a lot of fun, as you see, and it doesnt require you to use the "sudo" prefix.

## ⛏️ Built Using <a name = "built_using"></a>
- [C++](http://www.cplusplus.com/) - Main programming language.
- [MacPT](https://github.com/DiegoMagdaIeno/MacPT) - Backend/Package manager.
- [Project Serna](https://sernarepo.com/) - Main repository.

## ✍️ Authors <a name = "authors"></a>
- [@DiegoMagdaleno](https://github.com/DiegoMagdaIeno) - NVS build and implementation.
- [@Diatrus](https://github.com/Diatrus) - Source code cleaning, better help commands.

See also the list of [contributors](https://github.com/kylelobo/The-Documentation-Compendium/contributors) who participated in this project.

## 🎉 Acknowledgements <a name = "acknowledgement"></a>
- [Sysget by emilengler](https://github.com/emilengler/sysget) 
- [PacAPT by ICY](https://github.com/icy/pacapt)
