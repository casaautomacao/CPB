#include <Wire.h>
#include "Adafruit_MCP23017.h"
Adafruit_MCP23017 mcp;


void setup() {
  mcp.begin();
  mcp.pinMode(5, INPUT);
  mcp.pinMode(6, INPUT);
  mcp.pinMode(7, INPUT);
}

void loop() {
  
  mcp.digitalRead(5); // leitura da entrada do multiplexador 5
  mcp.digitalRead(6); // leitura da entrada do multiplexador 6
  mcp.digitalRead(7); // leitura da entrada do multiplexador 7

}
