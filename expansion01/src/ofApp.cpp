#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	
	sprite.load("img/test.jpg");

	// alloue l'espace de Fbo et clear la zone
	fbo.allocate(1024,768);
	fbo.begin();
	ofClear(255,255,255, 0);
	fbo.end();
	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
	if ( x >= 1024 ){
		sensX = -1;
	} else if ( x <= 0 ){
		sensX = 1;
	}
	if ( y >= 768 ){
		sensY = -1;
	} else if ( y <= 0 ){
		sensY = 1;
	}
	x = x + 3 * sensX;
	y = y + 3 * sensY;

	// show fps in title.
	std::stringstream strm;
	strm << "fps: " << ofGetFrameRate();
	ofSetWindowTitle(strm.str());

	fbo.begin();
	ofClear(255,255,255, 0);
	sprite.draw(x,y);
	fbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
	//fbo.draw(0,0);
	sprite.drawSubsection(x,y,30,60,0,0,30,60);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
