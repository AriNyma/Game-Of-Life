#include "header.h"

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/

int main()
{
  struct cell table1 [SIZE_COL][SIZE_ROW];
  struct cell table2 [SIZE_COL][SIZE_ROW];

  intialize_table(table1);
  intialize_table(table2);

  char state_c[SIZE_COL];
  read_file(table1, state_c);
  read_file(table2, state_c);
  
  show_current_generation(table1);
  show_current_generation(table2);

  int i;

  for (i = 0; i < 10; i++)
  {
    future_generation(table1);
    future_generation(table2);
    show_current_generation(table1);
    show_current_generation(table2);
  }
  return 0;
} /* end of main */