#pragma once
#include "GameVariable.h"

class Block{
public:
	Block();
	void createMap();
	void drawMap();
private :
	ofFbo fbo;
	ofImage spriteSheet,background;
};