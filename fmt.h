/*Copyright 2019-2023 Kai D. Gonzalez*/

#ifndef FMT_H
#define FMT_H

#include <stdio.h>

#define error(msg) fprintf(stderr, "%s\n", msg); exit(1);

// allows you to format a string similar to Python's str.format() function
// see https://docs.python.org/3/library/string.html#formatstrings
// hello, {} -> ("hello, world") -> format("hello, {}", "world")
char* format(const char* fmt, ...);

#endif
