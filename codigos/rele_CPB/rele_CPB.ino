#include <Wire.h>
#include "Adafruit_MCP23017.h"

Adafruit_MCP23017 mcp;

void setup() 

{
  
mcp.begin();
  
mcp.pinMode(0, OUTPUT);     // declaração de um pino de saída Relé 1
mcp.pinMode(1, OUTPUT);     // declaração de um pino de saída Relé 2
mcp.pinMode(2, OUTPUT);     // declaração de um pino de saída Relé 3

}

void loop() 
{

mcp.digitalWrite(0, HIGH);    // liga a saída 0 do MCP    (relé 1 da CPB) 
mcp.digitalWrite(0, LOW);     // desliga a saída 0 do MCP (relé 1 da CPB)

mcp.digitalWrite(1, HIGH);    // liga a saída 0 do MCP    (relé 2 da CPB) 
mcp.digitalWrite(1, LOW);     // desliga a saída 0 do MCP (relé 2 da CPB)

mcp.digitalWrite(2, HIGH);    // liga a saída 0 do MCP    (relé 3 da CPB) 
mcp.digitalWrite(2, LOW);     // desliga a saída 0 do MCP (relé 3 da CPB)

}
