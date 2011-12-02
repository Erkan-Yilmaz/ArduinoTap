#include <ArduinoTap.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  pass("foo");
  diag("We should never get here");

  for (;;) {}
}


