# Cryptography
Advanced Encryption Standard (AES) code implemented in two graphical user interfaces (GUIs): AES-256_GUI and AES-128_GUI

## AES-256_GUI
Written by Walt Kilar in 2010 for Norwich University MSIA project.

### Overview
Simple AES-256 application with QT graphical interface

### Files
* AES-256
* AES-256_GUI.pro
* AES-256.h
* AES-256.pro
* AES_algorithm.cpp
* AES-QT.pro
* AFC.ico
* main.cpp
* mainwindow.cpp
* mainwindow.h
* mainwindow.ui
* Makefile
* myico.rc
* README.md
* StdAfx.h
* Test Vectors.txt

### Installation
* qmake -project
* qmake AES-256_GUI.pro
* make

### Usage
* ./AES-256

## AES-128_GUI
Written by Walt Kilar in 2010 for Norwich University MSIA project.

## Overview
Simple AES-128 application with QT graphical interface

### Files
* aes-128.cpp
* aes-128_gui.pro
* aes-128.h
* aes-128_main.cpp
* aes-128_mainwindow.cpp
* aes-128_mainwindow.h
* aes-128_mainwindow.ui
* aes-gui.pro
* aes_lookup_tables.cpp
* Makefile
* README.md

### Installation
* qmake -project
* qmake aes-128_gui.pro
* make

### Usage
./aes-128_gui

### To-do
* Add capability to use different key lengths
* Add capability to read in key files and messages
