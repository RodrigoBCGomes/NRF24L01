#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio (9,10);                                            //Criando o rádio
const byte endereco[6] = "123890"                             //Mesmo endereço so Slave

int pinoBotao = 2;                                            //Pino do botão do arduino
int estadoBotao = 0;                                          //Variável para armazenar o estado

void setup() {

}

void loop() {

}
