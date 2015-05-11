//Created by Jiteng Liu (Leo)

#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {       //To define the basic environment conditions before the program starts.
	ofSetVerticalSync(true);
	ofSetFrameRate(120);        //set up the frame rate
	finder.setup("haarcascade_frontalface_alt2.xml");       //load the file
	finder.setPreset(ObjectFinder::Fast);       //set up the preset
	finder.getTracker().setSmoothingRate(.3);       //set up the tracker
	cam.initGrabber(640, 480);      //set up the size
	sunglasses.loadImage("Mustache.png");       //load the picture
	ofEnableAlphaBlending();
}

void ofApp::update() {      //give more define of code
	cam.update();
	if(cam.isFrameNew()) {      //set up the frames
		finder.update(cam);
	}
}

void ofApp::draw() {        //To excute the code.
	cam.draw(0, 0);     //the camera draw
	
	for(int i = 0; i < finder.size(); i++) {        //to start the size
		ofRectangle object = finder.getObjectSmoothed(i);
		sunglasses.setAnchorPercent(.5, -.3);       //set up the positation
		float scaleAmount = .5 * object.width / sunglasses.getWidth();      //set up the size
		
        ofPushMatrix();     //to sart the matrix
		ofTranslate(object.x + object.width / 2., object.y + object.height * .42);      //set up the position and size
		ofScale(scaleAmount, scaleAmount);
		sunglasses.draw(0, 0);      //draw the sunglasses
		ofPopMatrix();      //finish the push matrix
		
        ofPushMatrix();     //to sart the matrix
		ofTranslate(object.getPosition());      //set up the position
		ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
		ofLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);        //set up the line
		ofPopMatrix();      //finish the push matrix
	}
}
