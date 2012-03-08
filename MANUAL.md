
MANUAL
======


Writing Tests
--------------

See `libraries/ArduinoTap/examples`.

Running Tests
-------------

    $ cat examples/manual/manual.ino
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

With `runino` :

    $ runino examples/manual/manual.ino
    # Board Arduino Uno
    # Building ... in /tmp/4NfCruSlX_
    # Binary sketch size: 3310 bytes (of a 32256 byte maximum)
    # Done building
    # Uploading to board ...
    # Done uploading
    # Running on board ...
    1..5
    ok 1 - true
    ok 2 - 1 is true
    ok 3 - false
    ok 4 - 0 is false
    ok 5 - addition
    # Done with ArduinoTap.
    # Done running

Now, with `prove` :

    $ prove --exec=runino examples/manual/manual.ino
    examples/manual/manual.ino .. ok
    All tests successful.
    Files=1, Tests=5, 10 wallclock secs ( 0.03 usr  0.09 sys +  1.00 cusr  1.89 csys =  3.01 CPU)
    Result: PASS

If your continuous integration tool (for example, [Jenkins](http://jenkins-ci.org/))
requires the JUnix XML format.

    $ prove --formatter=TAP::Formatter::JUnit --exec=runino examples/manual/manual.ino
    <testsuites>
      <testsuite failures="0"
                 errors="0"
                 tests="5"
                 name="examples_manual_manual_ino">
        <testcase name="1 - true"></testcase>
        <testcase name="2 - 1 is true"></testcase>
        <testcase name="3 - false"></testcase>
        <testcase name="4 - 0 is false"></testcase>
        <testcase name="5 - addition"></testcase>
        <system-out><![CDATA[# Board Arduino Uno
    # Building ... in /tmp/cUUJsv6trA
    # Binary sketch size: 3310 bytes (of a 32256 byte maximum)
    # Done building
    # Uploading to board ...
    # Done uploading
    # Running on board ...
    1..5
    ok 1 - true
    ok 2 - 1 is true
    ok 3 - false
    ok 4 - 0 is false
    ok 5 - addition
    # Done with ArduinoTap.
    # Done running
    ]]></system-out>
        <system-err></system-err>
      </testsuite>
    </testsuites>

If your results must be stored first, and processed after.

    $ runino examples/manual/manual.ino > manual.tap
    $ prove --source=TAP::Parser::SourceHandler::RawTAP manual.tap
    manual.tap .. ok
    All tests successful.
    Files=1, Tests=5,  0 wallclock secs ( 0.02 usr +  0.07 sys =  0.09 CPU)
    Result: PASS

A [Smolder](http://search.cpan.org/~wonko/Smolder/) server aggregates test reports sent
by various submittors which could work on various hosts, with various Arduino boards.

    $ prove --archive=test_report.tar.gz --exec=runino examples/manual/manual.ino
    examples/manual/manual.ino .. ok
    All tests successful.
    Files=1, Tests=5, 12 wallclock secs ( 0.01 usr  0.04 sys +  0.95 cusr  2.54 csys =  3.54 CPU)
    Result: PASS

    TAP Archive created at ./test_report.tar.gz
    $ curl -F "platform=linux" -F "revision=100" -F "comments=uno" \
        -F "report_file=@test_report.tar.gz" \
        http://a.smolder.org/app/public_projects/process_add_report/1

