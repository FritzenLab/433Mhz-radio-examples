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
  pinMode(D7, INPUT_PULLDOWN);

  Serial.println("Transmissor RF 433 MHz");
  Serial.println("Iniciando.....................");
  delay(2000);

  //Pino DAT e transmissao de dados
  //pinMode(D2, OUTPUT);
  rfsense.enableTransmit(D2);
  delay(1000);

}

void loop()
{
  //Verifica se o botao foi pressionado
  int botao = digitalRead(D7);
  if(botao == 1){
    rfsense.send(1, 8);
  } else{
    rfsense.send(0, 8);
  }
  
  
  delay(200);
}
