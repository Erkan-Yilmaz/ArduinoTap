
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "ArduinoTap.h"


static int _curr_test = 0;
static int _expected_tests = 0;
static bool _have_plan = false;
static bool _no_plan = false;
static bool _have_output_plan = false;
static bool _done_testing = false;
static bool _is_passing = true;
static int _todo_upto = -1;
static const char *_todo_reason = NULL;

#if defined(UBRRH) || defined(UBRR0H)
static Print *_out = &Serial;
static Print *_failure_out = &Serial;
#else
static Print *_out = NULL;
static Print *_failure_out = NULL;
#endif


int plan() {
    return _expected_tests;
}

static inline void not_yet_plan() {
    if (_have_plan) {
        _failure_out->println("You tried to plan twice");
        exit(-1);
    }
}

void plan(int nb) {
    not_yet_plan();
    if (nb < 0) {
        _failure_out->print("Number of tests must be a positive integer.  You gave it '");
        _failure_out->print(nb);
        _failure_out->println("'.");
        exit(-1);
    }
    _out->print("1..");
    _out->println(nb);
    _have_plan = true;
    _have_output_plan = true;
    _expected_tests = nb;
}

void no_plan() {
    not_yet_plan();
    _have_plan = true;
    _no_plan = true;
}

void skip_all(const char *const reason) {
    not_yet_plan();
    _out->print("1..0 # SKIP ");
    _out->println(reason);
    _have_output_plan = true;
    exit(0);
}

void done_testing() {
    done_testing(_curr_test);
}

void done_testing(int nb) {
    if (_done_testing) {
        _out->println("done_testing() was already called");
    }
    else {
        _done_testing = true;
        if ((_expected_tests > 0) && (_expected_tests != nb)) {
            _out->print("#    planned to run ");
            _out->print(_expected_tests);
            _out->print(" but done_testing() expects ");
            _out->println(nb);
        }
        else {
            _expected_tests = nb;
        }
        if (! _have_output_plan) {
            _out->print("1..");
            _out->println(nb);
            _have_output_plan = true;
        }
        if ((_expected_tests != _curr_test) || (_curr_test == 0)) {
            _is_passing = false;
        }
        _out->println("# Done with ArduinoTap.");
    }
}

void bail_out(const char *const reason) {
    _out->print("Bail out!");
    if (reason != NULL) {
        _out->print("  ");
        _out->print(reason);
    }
    _out->println();
    exit(-1);
}

static inline void need_plan() {
    if (! _have_plan) {
        _failure_out->println("You tried to run a test without a plan");
        exit(-1);
    }
}

void _ok(const bool test, const char *const file, const int line, const char *const name) {
    need_plan();
    ++_curr_test;
    if (! test) {
        _out->print("not ");
    }
    _out->print("ok ");
    _out->print(_curr_test);
    if (name != NULL) {
        _out->print(" - ");
        _out->print(name);
    }
    if ((_todo_reason != NULL) && (_todo_upto >= _curr_test)) {
        _out->print(" # TODO # ");
        _out->print(_todo_reason);
    }
    _out->println();
    if (! test) {
        _out->print("#    Failed");
        if (_todo_upto >= _curr_test) {
            _out->print(" (TODO)");
        }
        else {
            _is_passing = false;
        }
        _out->print(" test (");
        _out->print(file);
        _out->print(" at line ");
        _out->print(line);
        _out->println(")");
    }
}

void todo(const char *const reason, int count) {
    _todo_upto = _curr_test + count;
    _todo_reason = reason;
}

void skip(const char *const reason, int count) {
    need_plan();
    for (int i = 0; i < count; i++) {
        ++_curr_test;
        _out->print("ok ");
        _out->print(_curr_test);
        _out->print(" - # skip");
        if (reason != NULL) {
            _out->print(" ");
            _out->print(reason);
        }
        _out->println();
    }
}

void todo_skip(const char *const reason) {
    need_plan();
    ++_curr_test;
    _out->print("not ok ");
    _out->print(_curr_test);
    _out->print(" - # TODO & SKIP");
    if (reason != NULL) {
        _out->print(" ");
        _out->print(reason);
    }
    _out->println();
}

void skip_rest(const char *const reason) {
    skip(reason, _expected_tests - _curr_test);
}

void diag(const char *const msg) {
    _out->print("# ");
    _out->println(msg);
}

void output(Print &out) {
    _out = &out;
    _failure_out = &out;
}

Print &output() {
    return *_out;
}

bool is_passing() {
    return _is_passing;
}

