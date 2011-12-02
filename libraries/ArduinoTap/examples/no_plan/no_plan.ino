#include <ArduinoTap.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  no_plan();
  ok(true, "foo");
  done_testing(1);

  for (;;) {}
}


