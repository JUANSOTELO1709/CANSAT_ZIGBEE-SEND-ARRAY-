#include <SoftwareSerial.h>          // Incluir librería SoftwareSerial para comunicación
 
SoftwareSerial XBee(10, 11);         // Definir pines de SoftwareSerial: RX = 10, TX = 11
 
void setup() {
  Serial.begin(115200);              // Iniciar comunicación con la PC para depuración
  XBee.begin(115200);                // Iniciar comunicación con el módulo XBee
 
  randomSeed(analogRead(0));         // Semilla para el generador de números aleatorios para obtener resultados variados
}
 
void loop() {
  int randomNumber = random(256);    // Generar un número aleatorio entre 0 y 255
  
  XBee.print('<');                   // Marcador de inicio de transmisión
  XBee.print(randomNumber);          // Enviar el número generado aleatoriamente
  XBee.println('>');                 // Marcador de fin de transmisión
 
  Serial.print("Envia numero: ");    // Salida de depuración al Monitor Serial
  Serial.println(randomNumber);
 
  delay(1000);                       // Retraso entre envíos para evitar saturación
}
