#include <Crescer.h>


Tempora tempCom;
Tempora tempImpr;
int erros = 0;
//int count1 = 0;
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
  MB_40009,       //PWM   PIN_09
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


// I1 = 45
// I2 = 46
// I3 = 47
// I4 = 48
// I5 = 49



int P_direita = 47;
int P_esquerda = 48;
int P_contaGiro = 45;
int P_contaGiro2 = 46;
int P_Corte = 49;

int L_CntGiro;
int L_CntGiro2;
int L_Corte;
int L_dir;
int L_esq;

int FC_Hori [2];
long CursoMax = 15000;
int SMoviment;
int puls = 0;
float LargBobina;
float LargFilamento;
int TotalPassos = 0;

int pulso = 37;
int dir = 38;
int ene = 39;
int teste13 = 13;
/*
  int pulso = 2;
  int dir = 5;
  int ene = 8;
  int teste13 = 13;
*/
int OnComuinc = A3;
int vel = 10;
int setacel = 0;
int passoRef = 0;

Tempora tempAcel;
Tempora Impressao;

unsigned int count1 = 0;
float Multiply = 31343;
float Potencia = -1.001;

int Divisor = 0;

int referenciar = 0;


void setup() {

  Serial.begin(9600);


  tempCom.defiSP(200);
  tempImpr.defiSP(1000);


  tempAcel.defiSP(20);
  Impressao.defiSP(500);


  modbus_configure(&Serial, 9600, SERIAL_8N2, 1, 13, MB_REGS, holdingRegs);

  // modbus_update_comms(baud, byteFormat, id) is not needed but allows for easy update of the
  // port variables and slave id dynamically in any function.
  modbus_update_comms(9600, SERIAL_8N2, 1);

}


void loop() {

  holdingRegs[MB_40015] = analogRead(A0); // envia para IHM



  modbus_update();



  analogWrite (10, holdingRegs[MB_40005]); // recebe da IHM

  delay(20);



}
