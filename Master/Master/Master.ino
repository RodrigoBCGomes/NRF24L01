#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio (9,10);                                            //Criando o rádio
const byte endereco[6] = "123890";                            //Mesmo endereço so Slave

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
  if(digitalRead(pinoBotao) == HIGH){                         //Se a leitura do pino got HIGH, executa
    estadoBotao = 1;                                          //Variável recebe valor 1
    radio.write(&estadoBotao,sizeof(estadoBotao));            //Envia ao receptor os dados
  }else{                                                      //Senão, executa  
        if(digitalRead(pinoBotao) == LOW){                    //Se a leitura do pino for igual a LOW, executa
        estadoBotao = 0;                                      //Variável recebe valor 0
        radio.write(&estadoBotao,sizeof(estadoBotao));        //Envia ao receptor os dados
      }
  }
}
