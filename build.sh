#!/bin/bash

if [ $1 == "clean" ] ; then
	rm -f PixelStrip.zip
	rm -rf build
else
    mkdir -p build/PixelStrip
    cp src/*.cpp build/PixelStrip
    cp src/*.h build/PixelStrip
    cp -r examples build/PixelStrip
    cp keywords.txt build/PixelStrip
    cp README.md build/PixelStrip
    cp library.properties build/PixelStrip
    cd build
    zip -r ../PixelStrip.zip PixelStrip
    cd ..
fi

