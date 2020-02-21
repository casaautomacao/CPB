
#include <Wire.h>
#include "Adafruit_MCP23017.h"

Adafruit_MCP23017 mcp;

void setup() 

{
mcp.begin();  

mcp.pinMode(8, OUTPUT);     // declaração de um pino de saída optoacoplada 1
mcp.pinMode(9, OUTPUT);     // declaração de um pino de saída optoacoplada 2


}

void loop() 
{

mcp.digitalWrite(8, HIGH);    // liga a saída optoacoplada 1
mcp.digitalWrite(8, LOW);     // desliga a saída optoacoplada 1
mcp.digitalWrite(9, HIGH);    // liga a saída optoacoplada 2
mcp.digitalWrite(9, LOW);     // desliga a saída optoacoplada 2

}
