
#ifndef ArduinoTap_h
#define ArduinoTap_h

#include <Print.h>


extern void plan(int nb);
extern int plan();
extern void no_plan();
extern void skip_all(const char *const reason);
extern void done_testing();
extern void done_testing(int nb);
extern void bail_out(const char *const reason=NULL);
extern void _ok(bool test, const char *const file, int line, const char *const name=NULL);
extern void todo(const char *const reason=NULL, int count=1);
extern void skip(const char *const reason=NULL, int count=1);
extern void todo_skip(const char *const reason=NULL);
extern void skip_rest(const char *const reason=NULL);
extern void diag(const char *const msg);
extern void output(Print &out);
extern Print &output();
extern bool is_passing();

#define ok(test, ...)                   _ok((test), __FILE__, __LINE__, ##__VA_ARGS__)
#define nok(test, ...)                  _ok(!(test), __FILE__, __LINE__, ##__VA_ARGS__)
#define pass(...)                       _ok(true, __FILE__, __LINE__, ##__VA_ARGS__)
#define fail(...)                       _ok(false, __FILE__, __LINE__, ##__VA_ARGS__)
#define is(got, expected, ...) \
    { \
        bool e = (got) == (expected); \
        _ok(e, __FILE__, __LINE__, ##__VA_ARGS__); \
        if (! e) { \
            Print &out = output(); \
            out.print("#         got: "); \
            out.println(got); \
            out.print("#    expected: "); \
            out.println(expected); \
        } \
    }
#define isnt(got, expected, ...) \
    { \
        bool e = (got) != (expected); \
        _ok(e, __FILE__, __LINE__, ##__VA_ARGS__); \
        if (! e) { \
            Print &out = output(); \
            out.print("#         got: "); \
            out.println(got); \
            out.println("#    expected: anything else"); \
        } \
    }


#endif

