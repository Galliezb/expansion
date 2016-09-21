#pragma once
#include "ClassBlock.h"
// constructeur
Block::Block(){
	// chargement des images
	spriteSheet.load("img/spriteSheet.png");
	background.load("img/fond01.jpg");

	// prépare la taille de la carte
	fbo.allocate(3840, 2560);

	createMap();

}
void Block::drawMap(){	
	fbo.getTexture().drawSubsection(0,0,Vg::widthScreen,Vg::heightScreen,Vg::posHautGaucheCameraX,Vg::posHautGaucheCameraY,Vg::widthScreen,Vg::heightScreen);
}
void Block::createMap(){

	fbo.begin();

	// Carte de taille 3840 * 2560 ( case de 32 pixels )
	// soit 120*80 cases au total
	// 20 de ciel ( donc 0-19, minable à partir de 20 )
	// centre des cases en X = 0-59 / 60-119

	int xMin = 59-Vg::numberOfCaseMapX/2;
	int yMin = 59-Vg::numberOfCaseMapY/2;

	/****************************   Dessiner le ciel   **********************************/
	background.drawSubsection(0,0,3840,640,0,0);


	/****************************   Dessiner les cases   **********************************/
	for(int y=20;y<80;y++){
		for(int x=0;x<120;x++){

			// case non disponible.
			if ( x < xMin || y > yMin ){
				spriteSheet.drawSubsection(x*32,y*32,32,32,288,0);
			} else {
				spriteSheet.drawSubsection(x*32,y*32,32,32,64,0);
			}

		}
	}

	fbo.end();

}
