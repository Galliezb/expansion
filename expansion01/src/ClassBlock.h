#pragma once
#include "GameVariable.h"

class Block{
public:
	Block();
	void createMap();
	void drawMap();
	void init();
private :
	ofFbo fbo;
	ofImage spriteSheet,background, navette, robot;
};