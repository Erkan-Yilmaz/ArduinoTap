#include <ArduinoTap.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  plan(5);
  ok(true, "true");
  ok(1, "1 is true");
  nok(false, "false");
  nok(0, "0 is false");
  is(1 + 1, 2, "addition");
  done_testing();

  for (;;); // DON'T LOOP
}
