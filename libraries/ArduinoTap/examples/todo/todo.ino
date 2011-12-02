#include <ArduinoTap.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  plan(7);

  todo("Just testing the todo interface", 2);
  fail("Expected failure");
  fail("Another expected failure");

  pass("This is not todo");

  todo("Just testing the todo interface");
  fail("Yet another failure");

  pass("This is still not todo");

  if (true) {
    todo_skip("Just testing todo_skip");
  }
  else {
    fail("Just testing todo");
  }

  pass("Again"); 
  done_testing();

  for (;;) {}
}

