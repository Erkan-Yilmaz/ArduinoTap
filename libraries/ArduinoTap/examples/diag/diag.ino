#include <ArduinoTap.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  diag("message 1");
  plan(1);
  diag("message 2");
  pass("foo");
  diag("message 3");
  done_testing();

  for (;;);
}

