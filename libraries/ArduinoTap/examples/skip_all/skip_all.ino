#include <ArduinoTap.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  skip_all("Goodbye");
  diag("We should never get here");

  for (;;) {}
}


