//Programa: Mini Transmissor RF 433 MHz H34A
//Autor: Arduino e Cia

#include <RCSwitch.h>

RCSwitch rfsense = RCSwitch();

//boolean envia_dado = 1;
int analog;

void setup()
{
  Serial.begin(9600);
  //Pino push-button
  //pinMode(7, INPUT_PULLUP);

  Serial.println("Transmissor RF 433 MHz");
  Serial.println("Iniciando.....................");
  delay(2000);

  //Pino DAT e transmissao de dados
  //pinMode(D2, OUTPUT);
  rfsense.enableTransmit(D2);
  delay(1000);

  analogReadResolution(12);
}

void loop()
{
  //Verifica se o botao foi pressionado
  //int botao = digitalRead(7);
  analog= analogRead(A0);
  rfsense.send(analog, 12);
  delay(1000);
}
