
#include <EEPROM.h>
#include <Crescer.h>
#include <SoftwareSerial.h>
SoftwareSerial supervisao(2, 3); // RX, TX

#include <Wire.h>
#include "Adafruit_MCP23017.h"

Adafruit_MCP23017 mcp;

Tempora tempCom;
Tempora tempImpr;
int erros = 0;
int count1 = 0;
//int Divisor = 0;

enum {
  MB_40000,       //A0
  MB_40001,       //A1
  MB_40002,       //A2
  MB_40003,       //A3
  MB_40004,       //A4
  MB_40005,       //A5
  MB_40006,       //A6
  MB_40007,       //A7
  //SAIDAS PWM
  MB_40008,       //PWM  PIN_06
  MB_40009,       //PWM  PIN_09
  MB_40010,       //PWM  PIN_10
  MB_40011,       //PWM  PIN_11
  //SAIDAS DIGITAIS
  MB_40012,        //PIN_07
  MB_40013,        //PIN_08
  MB_40014,        //PIN_12
  MB_40015,        //PIN_13
  //ENTRDAS DIGITAIS
  MB_40016,      //PIN_02
  MB_40017,      //PIN_03
  MB_40018,      //PIN_04
  MB_40019,      //PIN_05
  // Aqui você pode criar mais registradores  porém o elipse  demo fica limitado em 20 tags.  Lembrete os registradores e tags são na verdade variaveis.

  MB_REGS = 20,
};

unsigned int holdingRegs[MB_REGS]; // function 3 and 16 register array

void setup() {



  supervisao.begin(9600);
  Serial.begin(9600);

  tempCom.defiSP(200);
  tempImpr.defiSP(1000);
  // digitalWrite(A3, LOW);
  //  delay(1000);

  modbus_configure(&Serial, 9600, SERIAL_8N2, 1, 13, MB_REGS, holdingRegs);

  // modbus_update_comms(baud, byteFormat, id) is not needed but allows for easy update of the
  // port variables and slave id dynamically in any function.
  modbus_update_comms(9600, SERIAL_8N2, 1);

  delay(2000);
/*
  mcp.begin();      // use default address 0

  mcp.pinMode(4, OUTPUT);
  mcp.pinMode(0, OUTPUT);
  
   mcp.digitalWrite(0, HIGH);

  mcp.digitalWrite(4, LOW);

  delay(1000);
   mcp.digitalWrite(0, LOW);
*/
}

//variaveis para simulação
int passos_atuais = 0;
int total_passos = 0;
float passo_espal = 0;
float largula_bob = 0;

void loop() {




  if (tempCom.Saida(1)) // atualização temporizada obrigatória
  {


    holdingRegs[MB_40010] = passos_atuais; // envia para IHM
    holdingRegs[MB_40011] = total_passos;

    modbus_update(); // atualiza registradores

    passo_espal = holdingRegs[MB_40007]; // recebe da IHM
    largula_bob = holdingRegs[MB_40009];

    tempCom.Saida(0);
  }




  if (tempImpr.Saida(1)) //impressao temporizada e em uma serial criada para não conflitar com a serial do modbus
  {

    passos_atuais ++; // variavel para testar incremente em 1 registrador
    total_passos ++;

    supervisao.println( holdingRegs[MB_40010]);
    supervisao.println( holdingRegs[MB_40011]);
    supervisao.println(passo_espal);
    supervisao.println(largula_bob);

    tempImpr.Saida(0);
  }


}
