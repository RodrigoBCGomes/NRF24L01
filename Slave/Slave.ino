#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9,10);                                        //Pinos (CE,CSN)
const byte endereco[6] = "123890";                       //Endereço único por projeto

int pinoLed = 3;
int estadoBotao = 1;

void setup() {
  pinMode(pinoLed,OUTPUT);
  digitalWrite(pinoLed,LOW);
  radio.begin();
  radio.openReadingPipe(0,endereco);                     //Define o endereço que vai receber os dados
  radio.setPALevel(RF24_PA_HIGH);                        //Amplificador de sinal
  radio.startListening();                                //Definindo só como receptor de sinal 
}

void loop() {
  if(radio.available()){
    char text[32] = "";
    radio.read(&estadoBotao,sizeof(estadoBotao));        //Lê o estado que vem do rádio com ponteiros 
  }
  if(estadoBotao == 0){
    digitalWrite(pinoLed ,HIGH);
  }else{
    if(estadoBotao == 1){
      digitalWrite(pinoLed ,LOW);
    }
  }
  delay(5);
}
