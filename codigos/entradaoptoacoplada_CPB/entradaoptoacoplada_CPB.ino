
#include <Wire.h>
#include "Adafruit_MCP23017.h"

Adafruit_MCP23017 mcp;

void setup() 

{
mcp.begin();  
mcp.pinMode(10, INPUT);     // declaração de um pino de entrada optoacoplada 1
mcp.pinMode(11, INPUT);     // declaração de um pino de entrada optoacoplada 2
mcp.pinMode(12, INPUT);     // declaração de um pino de entrada optoacoplada 3
mcp.pinMode(13, INPUT);     // declaração de um pino de entrada optoacoplada 4
mcp.pinMode(14, INPUT);     // declaração de um pino de entrada optoacoplada 5
mcp.pinMode(15, INPUT);     // declaração de um pino de entrada optoacoplada 6

}

void loop() 
{

mcp.digitalRead(10);           // faz a leitura da entrada optoacoplada 1
mcp.digitalRead(11);           // faz a leitura da entrada optoacoplada 2
mcp.digitalRead(12);           // faz a leitura da entrada optoacoplada 3
mcp.digitalRead(13);           // faz a leitura da entrada optoacoplada 4
mcp.digitalRead(14);           // faz a leitura da entrada optoacoplada 5
mcp.digitalRead(15);           // faz a leitura da entrada optoacoplada 6

}
