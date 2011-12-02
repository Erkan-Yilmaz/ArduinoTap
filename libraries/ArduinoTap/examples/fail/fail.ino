#include <ArduinoTap.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  plan(2);
  fail();
  fail("foo");
  done_testing();

  for (;;) {}
}


