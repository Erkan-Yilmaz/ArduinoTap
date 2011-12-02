#include <ArduinoTap.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  bail_out("Goodbye");
  diag("We should never get here");

  for (;;) {}
}

