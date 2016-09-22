#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	
	sprite.load("img/test.jpg");

	// alloue l'espace de Fbo et clear la zone
	fbo.allocate(1024,768);
	fbo.begin();
	ofClear(255,255,255, 0);
	fbo.end();
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
		if ( Vg::posHautGaucheCameraX >= 3840-Vg::widthScreen ){Vg::posHautGaucheCameraX = 3840-Vg::widthScreen;}

	}
	// Camera Top Down
	if ( moveCameraUp ){

		Vg::posHautGaucheCameraY -=  Vg::scrollSpeed;
		if ( Vg::posHautGaucheCameraY <= 0 ){Vg::posHautGaucheCameraY = 0;}

	} else if ( moveCameraDown ){

		Vg::posHautGaucheCameraY += Vg::scrollSpeed;
		if ( Vg::posHautGaucheCameraY >= 2560-Vg::heightScreen ){Vg::posHautGaucheCameraY = 2560-Vg::heightScreen;}

	}
	std::cout << "camera Y : " << Vg::posHautGaucheCameraY << std::endl;
	std::cout << "hauteur fenetre: " << Vg::heightScreen << std::endl;

}

//--------------------------------------------------------------
void ofApp::draw(){
	fbo.draw(0,0);
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
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
