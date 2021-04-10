#!/bin/bash

cleanActualBuild() {
    if [ -d "build" ]
        then
            rm -rf build bin bin-obj TileEditor.sln TileEditor
    fi
}

setupProject () {
    pip install conan --upgrade
    mkdir build
    cd build
    conan install ..
    cd ../

    if [ $OSTYPE == "msys" ] || [ $OSTYPE == "win32" ]
        then
            chmod 777 premake/Windows/premake5.exe
            ./premake/Windows/premake5.exe vs2019
    elif [ $OSTYPE == "darwin" ]
        then
            chmod 777 premake/Mac/premake5
            ./premake/Mac/premake5 gmake
    else
        chmod 777 premake/Linux/premake5
        ./premake/Linux/premake5 gmake
    fi
}

askInput() {
    echo -e "Welcome to TileCreator setup."
    echo "1 Setup project."
    echo "2 Clear folder."
    read -p 'Enter value 1 or 2: ' choice

    if [ $choice == 1 ]
        then
            setupProject
    else
        cleanActualBuild
    fi
}

askInput