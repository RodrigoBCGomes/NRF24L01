#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio (9,10);                                            //Criando o rádio
const byte endereco[6] = "123890"                             //Mesmo endereço so Slave

int pinoBotao = 2;                                            //Pino do botão do arduino
int estadoBotao = 0;                                          //Variável para armazenar o estado

void setup() {
  pinMode(pinoBotao,INPUT_PULLUP);                            //Define o batão como entrada negativa
  radio.begin();                                              //Inicia o rádio
  radio.openWritingPipe(endereco);                            //Diz qual endereço o sinal está conversando
  radio.setPALevel(RF24_PA_HIGH);                             //Frequência alta
  radio.stopListening();                                      //Diz que ele não precisa ouvir, só enviar
}

void loop() {

}
