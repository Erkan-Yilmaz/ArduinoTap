#include <ArduinoTap.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  plan(4);

  if (false) {
    skip("We're not skipping", 2);
  }
  else {
    pass("not skipped in this branch");
    pass("not skipped again");
  }

  if (true) {
    skip("Just testing the skip interface.", 2);
  }
  else {
    fail("Deliberate failure");
    fail("And again");
  }

  done_testing();

  for (;;) {}
}
