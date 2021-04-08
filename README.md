# TileCreator
## _A tilemap editor because I'm bored_

TileCreator is a C++ application which will allow you to edit and create level for your games.
Qt-powered.

## Features

- None



## Installation

TileCreator requires [Conan](https://docs.conan.io/en/latest/installation.html) >=1.33.0 to run.

```sh
pip install conan
#check version 
conan --version

#if it's under 1.33 run
pip install conan --upgrade
```

After the installation of conan, create a `build` folder.

```sh
mkdir build
cd build
conan install ..
```

It will take some times... Then launch the premake.
```sh
./premake/{yourOS}/premake5 {yourIDE}
# for thie list of IDE execute /premake/{yourOS}/premake5 --help
```
