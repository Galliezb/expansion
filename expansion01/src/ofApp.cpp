#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	Vg::heightScreen = ofGetWindowHeight();
	Vg::widthScreen = ofGetWindowWidth();
	
	// creation de la map
	// bizarrement si on passe par le constructeur, heightscreen et widthscreen sont affecté après la création de la map
	// WTF OMG ?!?
	// Faut se renseigner sur le fonctionnement des compilateurs
	map.init();

}

//--------------------------------------------------------------
void ofApp::update(){

	// show fps in title.
	std::stringstream strm;
	strm << "fps: " << ofGetFrameRate();
	ofSetWindowTitle(strm.str());

	// Camera left right
	if ( moveCameraLeft ){

		Vg::posHautGaucheCameraX -=  Vg::scrollSpeed;
		if (Vg::posHautGaucheCameraX <= 0 ){Vg::posHautGaucheCameraX = 0;}

	} else if ( moveCameraRight ){

		Vg::posHautGaucheCameraX += Vg::scrollSpeed;
		if ( Vg::posHautGaucheCameraX >= Vg::fboAllocateWidth-Vg::widthScreen ){Vg::posHautGaucheCameraX = Vg::fboAllocateWidth-Vg::widthScreen;}

	}
	// Camera Top Down
	if ( moveCameraUp ){

		Vg::posHautGaucheCameraY -=  Vg::scrollSpeed;
		if ( Vg::posHautGaucheCameraY <= 0 ){Vg::posHautGaucheCameraY = 0;}

	} else if ( moveCameraDown ){

		Vg::posHautGaucheCameraY += Vg::scrollSpeed;
		if ( Vg::posHautGaucheCameraY >= Vg::fboAllocateHeight-Vg::heightScreen ){Vg::posHautGaucheCameraY = Vg::fboAllocateHeight-Vg::heightScreen;}

	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	map.drawMap();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	switch (key){
		case(OF_KEY_LEFT):  moveCameraLeft=true;break;
		case(OF_KEY_UP):    moveCameraUp=true;break;
		case(OF_KEY_RIGHT): moveCameraRight=true;break;
		case(OF_KEY_DOWN):  moveCameraDown=true;break;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	switch (key){
		case(OF_KEY_LEFT):  moveCameraLeft=false;break;
		case(OF_KEY_UP):    moveCameraUp=false;break;
		case(OF_KEY_RIGHT): moveCameraRight=false;break;
		case(OF_KEY_DOWN):  moveCameraDown=false;break;
	}

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
	Vg::heightScreen = ofGetWindowHeight();
	Vg::widthScreen = ofGetWindowWidth();
	map.init();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
