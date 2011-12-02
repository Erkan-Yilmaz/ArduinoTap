#include <ArduinoTap.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  plan(2);
  ok(true);
  ok(1, "foo");
  done_testing();

  for (;;) {}
}


