#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	
	sprite.load("img/vaisseau.png");

}

//--------------------------------------------------------------
void ofApp::update(){
	if ( x == 1024 ){
		sensX = -1;
	} else if ( x == 0 ){
		sensX = 1;
	}
	if ( y == 768 ){
		sensY = -1;
	} else if ( y == 0 ){
		sensY = 1;
	}
	x = x + 1 * sensX;
	y = y + 1 * sensY;
}

//--------------------------------------------------------------
void ofApp::draw(){
	sprite.drawSubsection(x,y,87,48,0,500,87,48);
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
