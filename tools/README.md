# Competitive Programming Tools

## boilerplate.cpp

This is a simple C++17 program that I like to use as a starting point for my projects.

It provides:
* The entire standard library available without a namespace qualifier
* A `DB` boolean that is true when a command line parameter is passed
* A `db` function that prints its argument to stderr when `DB` is true
* A `PULSE` statement that prints "Alive at line" and the line number to stderr when `DB` is true
* A typedef of `ll` to `long long`
* `FOR`, `UPTO`, `IN`, `EACH`, and `PR` (print) macros

## debug.cpp

This is a work in progress that is not ready for use yet. If I ever finish it, it will provide more robust printing than boilerplate.cpp. It may be incorporated into boilerplate.cpp in the future.

## tester

This is a shell script to assist in pre-submission testing of solutions. It is compatible with C++, C, Java, Python3, and Perl solutions at this time.

To use `tester`, install it to a location in your PATH (such as `/usr/local/bin/`) or to the directory with your source files (in which case it would of course be used with `./tester`). Place files named `[name].in` and `[name].out` or `[name].in1`, `[name].out1`, `[name].in2`, `[name].out2`, etc., in the same directory as your program `[name].cpp`, `[name].c`, `[name].java`, `[name].py`, or `[name].pl`. Then run `tester [filename]` in this directory to automatically compile (where applicable) your code and test it against the cases provided. For C++, the extension can be omitted from the filename and `.cpp` will be assumed (`./tester prob3.cpp` and `./tester prob3` are equivalent).

If a command-line argument is provided to `tester` (for example, `./tester prob3 d`), it will run in *debug mode*, which prevents `tester` from stopping after failed tests. The argument is also passed to your program, so if you're using boilerplate.cpp or another solution to check for a command line argument, you will get debug output from your program.

For each test case, `tester` displays your program's output (stderr and stdout are separated) and compares the output on `stdout` to the provided sample output using `diff`. The output of `diff` is also displayed; if the test passes, this will be blank. When not in debug mode, `tester` stops after a test fails.

Dependencies are, unsurprisingly, `bash` as well as `g++` for C++, `gcc` for C, `javac` and `java` for Java, `python3` for Python, and `perl` for Perl.