#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/

int main()
{
  struct cell table [SIZE_COL][SIZE_ROW];

  intialize_table(table);

  char state_c[SIZE_COL];
  read_file(table, state_c);

  show_current_generation(table);
  int i;

  for (i = 0; i < 10; i++)
  {
    future_generation(table);
    show_current_generation(table);
  }
  return 0;
} /* end of main */