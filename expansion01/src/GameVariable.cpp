#pragma once
#include "GameVariable.h"

// La hauteur et largeur d'écran sera initialisé via setup d'OF au chargement
int Vg::widthScreen=-1;
int Vg::heightScreen=-1;

// Nombre de cases horizontal ( DOIT ETRE PAIRE pour un affichage plus correct )
int Vg::numberOfCaseMapX=10;
// Nombre de case vertical
int Vg::numberOfCaseMapY=6;

// taille d'alocation de la map FBO
int Vg::fboAllocateWidth = -1;
int Vg::fboAllocateHeight = -1;

// position X et Y de la camera, par défaut e
int Vg::posHautGaucheCameraX=0;
int Vg::posHautGaucheCameraY=0;

// vitesse mouvement camera
int Vg::scrollSpeed = 10;

