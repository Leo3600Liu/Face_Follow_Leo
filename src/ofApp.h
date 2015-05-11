//Created by Jiteng Liu (Leo)

#pragma once

#include "ofMain.h"
#include "ofxCv.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	
	ofVideoGrabber cam;     //give a defination of camera
	ofxCv::ObjectFinder finder;
	ofImage sunglasses;     //load the image
};
