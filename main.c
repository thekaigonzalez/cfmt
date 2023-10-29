#include "fmt.h"

#include <stdio.h>
#include <stdlib.h>

main (void)
{
  char *n = format ("hello, {}{}", "world", "!");

  printf ("%s\n", n);

  free (n);
}
