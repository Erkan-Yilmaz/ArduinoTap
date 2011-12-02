#include <ArduinoTap.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  plan(3);
  isnt(-42, 42);
  isnt(-42, 42,  "foo");

  todo("good reason");
  isnt(42, 42,  "equals");

  done_testing();

  for (;;) {}
}


