#include <ArduinoTap.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  plan(3);
  is(42, 42);
  is(42, 42,  "foo");

  todo("good reason");
  is(0, 42,  "not equals");

  done_testing();

  for (;;) {}
}


