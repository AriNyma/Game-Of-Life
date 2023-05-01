#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: next_generation
 DESCRIPTION: creating the next generation according the current generation
	Input: Global constants and count_neighbours function result
	Output:
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
void future_generation(struct cell table[SIZE_COL][SIZE_ROW])
{
  int i, j;

  for(i = 0; i < SIZE_COL; i++)
  {
    for(j = 0; j < SIZE_ROW; j++)
    {
      int neighbours = count_neighbours(table, i, j);
      if(table[i][j].current == 0)
      {
        if(neighbours == 3)
        {
          table[i][j].future = 1;
        }
        else
        {
          table[i][j].future = 0;
        }
      }
      else if(table[i][j].current == 1)
      {
        if(neighbours < 2 || neighbours > 3)
        {
          table[i][j].future = 0;
        }
        else
        {
          table[i][j].future = 1;
        }
      }
    }
  }
   for(i = 0; i < SIZE_COL; i++)
  {
    for(j = 0; j < SIZE_ROW; j++)
    {
      table[i][j].current = table[i][j].future;
    }
  }
}
