#include <SPI.h>
#include <SD.h>

#define CHIP_SELECT 4

int initSD(void){
	if( !SD.begin(CHIP_SELECT) ){
		Serial.println("ERREUR: Carte absente ou endommagée !");
		return 1
	}

	Serial.println("NOTE: Carte initialisée !");
	return 0
}

int initWritingToFile(char* path, File* file){
	if( SD.exists(path) ){
		if( !SD.remove(path) ){
			Serial.println("ERREUR: Impossible de détruire le fichier " + String(path) + " !");
			return 1
		}
	}

	*file = SD.open(path, FILE_WRITE);
	if( !(*file) ){
		Serial.println("ERREUR: Impossible de créer/lire le fichier " + String(path) + " !");
		return 1
	}

	Serial.println("NOTE: Le fichier " + String(path) + " est en cours de lecture !");
	return 0
}

int writeStringToFile(char* buffer, int size, File* file){
	if( !file.write(buffer, size) ){
		Serial.println("ERREUR: Impossible d'écrire dans le fichier !");
		return 1
	}

	if( !file.flush() ){
		Serial.println("ERREUR: Impossible d'enregistrer sur la carte SD !");
		return 1
	}

	Serial.println("NOTE: Données enregistrées !");
	return 0
}
