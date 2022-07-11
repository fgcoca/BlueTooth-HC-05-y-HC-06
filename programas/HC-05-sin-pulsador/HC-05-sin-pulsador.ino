#include <SoftwareSerial.h>
// Definimos una conexión utilizando la librería
SoftwareSerial conex_BT(10, 11); // Recuerda cruzar RX con TX
void setup(){ 
  Serial.begin(9600);     // Velocidad de comunicación con el monitor serie
  Serial.println("Alimentamos el modulo HC-05 mientras se mantiene presionado el pulsador. Se habilita el modo AT2");
  Serial.println("El LED parpadea lentamente y el módulo listo para trabajar con comandos AT:");
  conex_BT.begin(38400);  // Inicializa el puerto serie o consola
}
void loop(){  
  if (conex_BT.available())
    Serial.write(conex_BT.read());
  if (Serial.available())
    conex_BT.write(Serial.read());
}
