#pragma once
#include "GameVariable.h"

// La hauteur et largeur d'écran sera initialisé via setup d'OF au chargement
int Vg::widthScreen=0;
int Vg::heightScreen=0;

// Nombre de cases a gauche et droite du centre ( max 60 et paire forcé )
int Vg::numberOfCaseMapX=10;
// Max profondeur de la carte ( 20 pour le ciel, 60 max profondeur )
int Vg::numberOfCaseMapY=6;

// position X et Y de la camera, par défaut e
int Vg::posHautGaucheCameraX=0;
int Vg::posHautGaucheCameraY=0;

// vitesse mouvement camera
int Vg::scrollSpeed = 10;

