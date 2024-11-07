//Programa: Circuito Receptor RF 433 MHz
//Autor: Arduino e Cia

#include <RCSwitch.h>

RCSwitch rfsense = RCSwitch();

void setup()
{
  Serial.begin(9600);
  //Pino do led
  pinMode(13, OUTPUT);

  //Receptor na interrupção 0 (pino digital 2)
  rfsense.enableReceive(0);

  Serial.println("Receptor RF 433 MHz");
  Serial.println("Iniciando.....................");
  delay(2000);
}

void loop()
{
  if (rfsense.available())
  {
    //Verifica o valor recebido pelo receptor
    int valor = rfsense.getReceivedValue();
    digitalWrite(13, HIGH);
          
    
    Serial.println(valor);
    rfsense.resetAvailable();  
  }else{
    digitalWrite(13, LOW);
  }
  
    
}