/*
  SD card read/write

 This example shows how to read and write data to and from an SD card file
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4

 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

#include <SPI.h>
#include <SD.h>

File myFile;
int menu_select;
int lastmenu_select;

void abririmagen1(void);
void abririmagen2(void);
void abririmagen3(void);

void setup()
{ 
  pinMode(PA_3, OUTPUT);
  
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  SPI.setModule(0);
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println("Iniciando la tarjeta SD");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output
  // or the SD library functions will not work.


  if (!SD.begin(PA_3)) {
    Serial.println("Falló la inicialización de la tarjeta SD!");
    return;
  }
  Serial.println("Inició la tarjeta SD correctamente");
  Serial.println(" ");
  
  }

void loop()
{
  if (menu_select == 0){
  Serial.println(" ");
  Serial.println("Seleccione la imagen que desea abrir");
  Serial.println("1. Imagen del cohete (Rocket.txt)");
  Serial.println("2. Imagen de Saturno (Saturno.txt)");
  Serial.println("3. Imagen de Luffy (Luffy.txt)");
  Serial.println(" ");
  }
  
  while(!Serial.available());
  menu_select = Serial.read();

  switch(menu_select){
    case 49:
      abririmagen1();
      break;
    case 50:
      abririmagen2();
      break;
    case 51: 
      abririmagen3();
      break;
    }
    delay(250);
}

void abririmagen1(void){
    // re-open the file for reading:
  myFile = SD.open("Rocket.txt");
  if (myFile) {
    Serial.println("Rocket.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
    Serial.println(" ");
  } else {
    // if the file didn't open, print an error:
    Serial.println("Error al abrir la imagen");
  }
  menu_select = 0;
 }
 
 void abririmagen2(void){
    // re-open the file for reading:
  myFile = SD.open("Saturno.txt");
  if (myFile) {
    Serial.println("Saturno.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
    Serial.println(" ");
  } else {
    // if the file didn't open, print an error:
    Serial.println("Error al abrir la imagen");
  }
  menu_select = 0;
 }
 
 void abririmagen3(void){
    // re-open the file for reading:
  myFile = SD.open("Luffy.txt");
  if (myFile) {
    Serial.println("Luffy.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
    Serial.println(" ");
  } else {
    // if the file didn't open, print an error:
    Serial.println("Error al abrir la imagen");
  }
  menu_select = 0;
 }
