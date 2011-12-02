#include <ArduinoTap.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  plan(5);
  pass("foo");
  pass("bad");
  done_testing();

  for (;;);
}

