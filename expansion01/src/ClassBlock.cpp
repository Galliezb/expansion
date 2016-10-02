#pragma once
#include "ClassBlock.h"
// constructeur
Block::Block(){
	// chargement des images
	spriteSheet.load("img/spriteSheet.png");
	background.load("img/fond01.jpg");
}
void Block::init(){

	// prépare la taille de la carte
	(Vg::numberOfCaseMapX*32 < Vg::widthScreen  ) ? Vg::fboAllocateWidth = Vg::widthScreen   : Vg::fboAllocateWidth  = Vg::numberOfCaseMapX*32;
	(Vg::numberOfCaseMapY*32 < Vg::heightScreen ) ? Vg::fboAllocateHeight = Vg::heightScreen : Vg::fboAllocateHeight = Vg::numberOfCaseMapY*32;
	fbo.allocate(Vg::fboAllocateWidth,Vg::fboAllocateHeight);

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

	int xMin = 0;
	cout << Vg::widthScreen << " VS " << Vg::numberOfCaseMapX*32 << endl;
	if ( Vg::widthScreen > Vg::numberOfCaseMapX*32 ){
		xMin = Vg::widthScreen/32/2 - Vg::numberOfCaseMapX/2;
	}
	int yMin = 0;
	/****************************   Dessiner le ciel   **********************************/


	/****************************   Dessiner les cases   **********************************/
	for(int y=0;y<Vg::fboAllocateHeight/32;y++){
		for(int x=0;x<Vg::fboAllocateWidth/32;x++){

			if ( y <= Vg::numberOfCaseMapY && x >= xMin && x <= xMin + Vg::numberOfCaseMapX ){
				spriteSheet.drawSubsection(x*32,y*32,32,32,64,32);
			}

		}
	}

	fbo.end();

}
