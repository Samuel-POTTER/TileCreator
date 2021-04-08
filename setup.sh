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
            until ./premake/Windows/premake5.exe vs2019; do
                spin
            done
            endspin
    elif [ $OSTYPE == "darwin" ]
        then
            until ./premake/Mac/premake5 gmake
            ./premake/Mac/premake5 xcode4; do
            spin
            done
            endspin
    else
        until ./premake/Linux/premake5 gmake; do
            spin
        done
        endspin
    fi
}

sp="/-\|"
sc=0
spin() {
   printf "\b${sp:sc++:1}"
   ((sc==${#sp})) && sc=0
}
endspin() {
   printf "\r%s\n" "$@"
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