
ArduinoTap : an Unit Testing library
====================================

Introduction
------------

ArduinoTap is a C/C++ port of the Perl5 module
[Test::More](http://search.cpan.org/~mschwern/Test-Simple/) on [Arduino](http://arduino.cc/>).

It uses the [Test Anything Protocol](http://en.wikipedia.org/wiki/Test_Anything_Protocol) as output,
that allows a compatibility with the Perl QA ecosystem.
For example, [prove](http://search.cpan.org/~andya/Test-Harness/bin/prove) a basic CLI,
or [Smolder](http://search.cpan.org/~wonko/Smolder/) a web-based smoke test aggregator server.

It allows a simple and efficient way to write tests (without OO style).

Some tests could be marked as TODO or skipped.

An additional script _runino_ allows to build a sketch, to upload it on an Arduino board, and
to capture its output. So, it is possible to use a continuous integration server which runs
a test suite containing many sketches.

    $ prove --exec=runino examples/*ok/*.ino examples/is*/*.ino

Bibliography
------------

* Ian Langworth, chromatic, [Perl Testing](http://oreilly.com/catalog/9780596100926) O'Reilly, 2005
* James W. Grenning, [Test Driven Development for Embedded C](http://pragprog.com/book/jgade/test-driven-development-for-embedded-c) The Pragmatic Bookshelf, 2009

Download
--------

ArduinoTap source can be downloaded from [GitHub](http://github.com/fperrad/ArduinoTap/downloads/).

Installation
------------

    $ sudo make install

Copyright and License
---------------------

Copyright 2011 Francois Perrad

This library is licensed under the terms of the Artistic License 2.0, like Perl.

