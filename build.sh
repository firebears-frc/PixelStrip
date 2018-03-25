#!/bin/bash

if [ $1 == "clean" ] ; then
	rm -f PixelStrip.zip
	rm -rf build
else
    mkdir -p build
    cp src/*.cpp build
    cp src/*.h build
    cp -r examples build
    cp keywords.txt build
    cp README.md build
    cp library.properties build
    cd build
	zip -r ../PixelStrip.zip *
	cd ..
fi


