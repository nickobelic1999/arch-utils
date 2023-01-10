#!/bin/zsh

#The following script was grabbed from here: https://authmane512.medium.com/how-to-build-an-apk-from-command-line-without-ide-7260e1e22676
# With changes made by Nick White

set -e

SDK_PATH=$2

AAPT=$SDK_PATH"/build-tools/33.0.1/aapt"
DX=$SDK_PATH"/build-tools/33.0.01/dx"
ZIPALIGN=$SDK_PATH"/build-tools/zipalign"
APKSIGNER=$SDK_PATH"/build-tools/apksigner" # /!\ version 26
PLATFORM=$SDK_PATH"/platforms/android-33/android.jar"

if [ "$1" == "clean" || "$1" == "CLEAN" ]; then
	echo "Cleaning..."
	rm -rf obj/*
	rm -rf src/com/example/helloandroid/R.java
fi

#if [ "$1" == "directories" || "$1" == "DIRECTORIES" ]; then
	echo "Creating directories..."
	mkdir -p src/com/example/helloandroid
	mkdir obj
	mkdir bin
	mkdir -p res/layout
	mkdir res/values
	mkdir res/drawable
#fi

echo "Generating R.java file..."
$AAPT package -f -m -J src -M AndroidManifest.xml -S res -I $PLATFORM

echo "Compiling..."
javac -d obj -classpath src -bootclasspath $PLATFORM -source 1.7 -target 1.7 src/com/example/helloandroid/MainActivity.java
javac -d obj -classpath src -bootclasspath $PLATFORM -source 1.7 -target 1.7 src/com/example/helloandroid/R.java

echo "Translating in Dalvik bytecode..."
$DX --dex --output=classes.dex obj

echo "Making APK..."
$AAPT package -f -m -F bin/hello.unaligned.apk -M AndroidManifest.xml -S res -I $PLATFORM
$AAPT add bin/hello.unaligned.apk classes.dex

echo "Aligning and signing APK..."
$APKSIGNER sign --ks mykey.keystore bin/hello.unaligned.apk
$ZIPALIGN -f 4 bin/hello.unaligned.apk bin/hello.apk

if [ "$1" == "test" || "$1" == "TEST" ]; then
	echo "Launching..."
	adb install -r bin/hello.apk
	adb shell am start -n com.example.helloandroid/.MainActivity
fi
