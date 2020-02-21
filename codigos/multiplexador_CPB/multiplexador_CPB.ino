
#include <Wire.h>
#include "Adafruit_MCP23017.h"

Adafruit_MCP23017 mcp;

void setup() 

{
mcp.begin();  
mcp.pinMode(0, OUTPUT);     // declaração de um pino de saída Relé 1
mcp.pinMode(1, OUTPUT);     // declaração de um pino de saída Relé 2
mcp.pinMode(2, OUTPUT);     // declaração de um pino de saída Relé 3
mcp.pinMode(3, OUTPUT);     // declaração de um pino de saída Reset GSM
mcp.pinMode(4, OUTPUT);     // declaração de um pino de saída Liga MAX3232
mcp.pinMode(5, INPUT);      // declaração de um pino de entrada digital 1
mcp.pinMode(6, INPUT);      // declaração de um pino de entrada digital 2
mcp.pinMode(7, INPUT);      // declaração de um pino de entrada digital 3
mcp.pinMode(8, OUTPUT);     // declaração de um pino de saída optoacoplada 1
mcp.pinMode(9, OUTPUT);     // declaração de um pino de saída optoacoplada 2
mcp.pinMode(10, INPUT);     // declaração de um pino de entrada optoacoplada 1
mcp.pinMode(11, INPUT);     // declaração de um pino de entrada optoacoplada 2
mcp.pinMode(12, INPUT);     // declaração de um pino de entrada optoacoplada 3
mcp.pinMode(13, INPUT);     // declaração de um pino de entrada optoacoplada 4
mcp.pinMode(14, INPUT);     // declaração de um pino de entrada optoacoplada 5
mcp.pinMode(15, INPUT);     // declaração de um pino de entrada optoacoplada 6

}

void loop() 
{

mcp.digitalWrite(0, HIGH);    // liga a saída 0 do MCP (relé 1 da CPB) 
mcp.digitalWrite(0, LOW);     // desliga a saída 0 do MCP (relé 1 da CPB)
mcp.digitalRead(5);           // faz a leitura da entrada 5 do MCP (entrada digital 1 da CPB)

}
