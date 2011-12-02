#include <ArduinoTap.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  plan(2);
  nok(false);
  nok(0, "foo");
  done_testing();

  for (;;) {}
}


