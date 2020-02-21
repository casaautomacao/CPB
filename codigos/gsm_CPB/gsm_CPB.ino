#include <SoftwareSerial.h>
SoftwareSerial gsm(A3, A2); // RX, TX
#include <Sim800l.h>
Sim800l Sim800l;

#include <Crescer.h>

Tempora temp1;

String avalia = "";
int conta = 0;

void setup()
{
  Serial.begin(9600);
  delay(1000);

  gsm.begin(9600);
  gsm.listen();

  comando ("AT");
  comando ("AT+CMGF=1");
  comando ("ATE0");
  delay(1500);
  comando ("AT+CNMI=1,2,0,0,0");
  delay(1000);
  temp1.defiSP(500);
}

int teste;

void loop()
{


  String comp = "";
  if (gsm.available() > 0) {

    String msggsm = "";
    while (gsm.available() > 0)
    {
      char letra = gsm.read();
      if (isAlphaNumeric(letra)) msggsm += letra;
    }
    int tam = msggsm.length();


    comp += msggsm[tam - 2];
    comp += msggsm[tam - 1];

    Serial.print("MSG1: ");
    Serial.println(msggsm);

    Serial.print("comp: ");
    Serial.println(comp);



    if (comp == "L1")  // compara mensagem recebida
    {
      digitalWrite(11, 0);
      Serial.println("Ligou1");
    }
    else if (comp == "D1")
    {
      digitalWrite(11, 1);
      Serial.println("Desligou1");
    }
    else if (comp == "L2")
    {
      digitalWrite(12, 0);
      Serial.println("ligou2");
    }
    else if (comp == "D2")
    {
      digitalWrite(12, 1);
      Serial.println("Desligou2");
    }
    
    delay(300);
  }

  int entrada = digitalRead(4);

  
  if (entrada == 0 or comp == "Le")  // envia mensagem
  {
    comando ("AT+CMGF=1");
    comando ("ATE0");
    comando ("AT+CNMI=1,2,0,0,0");

    gsm.print("AT+CMGS=");
    gsm.write(0x22);//aspa dupla
    gsm.print("+5551999999999");
    gsm.write(0x22);//aspa dupla
    gsm.println();

    delay(1000);
    gsm.print("Valor da entrada A0: ");
    gsm.println(teste);
    Serial.println(teste);

    delay(2000);

    gsm.write(0x1A);
    gsm.write(0x0D);
    gsm.write(0x0A);
    Serial.println("fim1");
    delay(2000);
    Serial.println("fim2");
  }

}
