
#define CS 4 // Chip Select

File datas;
int lognumero;

void logSurSD(float altitude){// AFAIRE : camera
  datas = SD.open("datas.csv");
  if(datas){
    datas.print(lognumero);
    datas.print(";");
    datas.println(altitude);
  }else{
    Serial.println("Problème avec 'datas.csv'!");
  }
}

void initSD(void){
  //Serial.begin(9600);
  Serial.println("Initialisation de la carte SD...");
  if(!SD.begin(CS)){
      Serial.println("Carte absente ou endommagée!");
      Serial.println("Arrêt du programme. ");
      while(1);
  }

  // fichier CSV
  SD.remove("data.csv");
  datas = SD.open("datas.csv", FILE_WRITE);
  if(datas){
    Serial.println("Carte initialisée...");
  }else{
    Serial.println("Problème avec 'datas.csv'!");
    Serial.println("Arrêt du programme. ");
  }
}