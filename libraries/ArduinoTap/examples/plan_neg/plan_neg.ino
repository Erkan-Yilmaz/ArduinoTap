#include <ArduinoTap.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  plan(-1);
  diag("We should never get here");

  for (;;) {}
}


