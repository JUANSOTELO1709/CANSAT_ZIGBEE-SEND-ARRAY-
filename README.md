# XBee Comunicación Serial

Este repositorio contiene dos ejemplos de código para la comunicación serial utilizando módulos XBee y la librería SoftwareSerial en Arduino.

## Ejemplo 1: Lectura de Mensajes desde XBee

### Descripción

Este ejemplo de código muestra cómo leer mensajes enviados desde un módulo XBee. El código detecta el inicio y el fin de un mensaje utilizando los caracteres `<` y `>`, respectivamente. Los mensajes recibidos se almacenan en un array y se convierten a enteros para su procesamiento.

### Código

```cpp
#include <SoftwareSerial.h>          // Incluir librería SoftwareSerial para comunicación
 
SoftwareSerial XBee(10, 11);         // RX = 10, TX = 11

bool started = false;                // Verdadero cuando se detecta el marcador de inicio
bool ended = false;                  // Verdadero cuando se detecta el marcador de fin
char incomingByte;                   // Almacenamiento para cada byte leído
char msg[4];                         // Array para ensamblar el mensaje entrante
byte index = 0;                      // Posición actual en el array

void setup() {
  Serial.begin(115200);              // Iniciar comunicación con la PC para depuración
  XBee.begin(115200);                // Iniciar comunicación con el módulo XBee
}

void loop() {
  while (XBee.available() > 0) {     // Comprobar si hay datos disponibles del XBee
    incomingByte = XBee.read();      // Leer el byte entrante

    if (incomingByte == '<') {       // Detectar inicio del mensaje
      started = true;
      index = 0;
      msg[index] = '\0';             // Limpiar el buffer
    } else if (incomingByte == '>') { // Detectar fin del mensaje
      ended = true;
      break;                         // Dejar de leer, procesar el mensaje
    } else if (started && index < 3) { // Almacenar el byte en el array msg si el mensaje ha comenzado
      msg[index] = incomingByte;
      index++;
      msg[index] = '\0';             // Terminar la cadena con nulo
    }
  }

  if (started && ended) {            // Si se recibió un mensaje completo, procesarlo
    int value = atoi(msg);           // Convertir el buffer a un entero
    Serial.print("Recibido: ");      // Salida de depuración al Monitor Serial
    Serial.println(value);

    started = false;                 // Reiniciar para el próximo mensaje
    ended = false;
  }
}
```
# Ejemplo 2: Envío de Números Aleatorios a través de XBee
## Descripción
Este ejemplo de código muestra cómo enviar números aleatorios generados en el Arduino a través de un módulo XBee. Los números se generan entre 0 y 255 y se envían con marcadores de inicio < y fin > para delimitar cada mensaje.

### Código


```cpp
#include <SoftwareSerial.h>          // Incluir librería SoftwareSerial para comunicación
 
SoftwareSerial XBee(10, 11);         // RX = 10, TX = 11

bool started = false;                // Verdadero cuando se detecta el marcador de inicio
bool ended = false;                  // Verdadero cuando se detecta el marcador de fin
char incomingByte;                   // Almacenamiento para cada byte leído
char msg[4];                         // Array para ensamblar el mensaje entrante
byte index = 0;                      // Posición actual en el array

void setup() {
  Serial.begin(115200);              // Iniciar comunicación con la PC para depuración
  XBee.begin(115200);                // Iniciar comunicación con el módulo XBee
}

void loop() {
  while (XBee.available() > 0) {     // Comprobar si hay datos disponibles del XBee
    incomingByte = XBee.read();      // Leer el byte entrante

    if (incomingByte == '<') {       // Detectar inicio del mensaje
      started = true;
      index = 0;
      msg[index] = '\0';             // Limpiar el buffer
    } else if (incomingByte == '>') { // Detectar fin del mensaje
      ended = true;
      break;                         // Dejar de leer, procesar el mensaje
    } else if (started && index < 3) { // Almacenar el byte en el array msg si el mensaje ha comenzado
      msg[index] = incomingByte;
      index++;
      msg[index] = '\0';             // Terminar la cadena con nulo
    }
  }

  if (started && ended) {            // Si se recibió un mensaje completo, procesarlo
    int value = atoi(msg);           // Convertir el buffer a un entero
    Serial.print("Recibido: ");      // Salida de depuración al Monitor Serial
    Serial.println(value);

    started = false;                 // Reiniciar para el próximo mensaje
    ended = false;
  }
}
```