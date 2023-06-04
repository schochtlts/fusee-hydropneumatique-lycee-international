#include "carteSD.h"

#define FILE_PATH "data.csv"

File mainFile;

void setup(void)
{
	Serial.begin(9600);

	if( initSD() ) goto terminate;
	if( initWritingToFile(FILE_PATH, &mainFile) ) goto terminate;
	return;

	terminate: while(1); // Seul moyen de mettre fin au programme
}

void loop(void)
{
	/*
	PROCESSUS DANS loop()

	1. Mesurer les vitesses angulaires et accélérations linéaires.
	2. Corriger l'erreur statique sur les valeurs.
	3. Prendre des photos avec les caméras.
	
	4. Convertir toutes les données en une suite de caractères.
	5. Ecrire le string sur la carte SD.

	6. Déclencher le parachute si nécéssaire. 
	*/
}
