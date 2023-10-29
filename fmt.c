#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <string.h> // strlen, memcpy, memset

#include "fmt.h"

char *
format(const char *fmt, ...)
{
  va_list args;
  va_start(args, fmt);

  int len = strlen(fmt);     // the length of the format string
  char *n = malloc(len * 2 + 1); // allocate memory for the result, allowing for possible expansion

  if (n == NULL)
    return NULL;

  int j = 0; // seperate index

  for (int i = 0; i < len; i++)
  {
    if (fmt[i] == '{' && fmt[i + 1] == '}')
    {
      char *v = va_arg(args, char *); // get the next arg

      if (v == NULL)
      {
          error("Missing argument for replacement");
      }

      int vlen = strlen(v); // the length of the replacement string

      memcpy(n + j, v, vlen); // copy the replacement string to the result
      
      j += vlen; // add the length of the replacement string to the result
      
      i += 1; // skip the '}'
    }
    else
    {
      n[j] = fmt[i];
      j++;
    }
  }

  va_end(args);

  n[j] = '\0'; // Null-terminate the result string

  return n;
}

