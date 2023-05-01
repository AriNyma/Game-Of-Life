#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: current_generation
 DESCRIPTION: print out the current table with the active and deactive nodes
	Input: Global constants
	Output:
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
void show_current_generation(struct cell table[SIZE_COL][SIZE_ROW])
{
  int i, j;
  for(i = 0; i < SIZE_COL; i++)
  {
    for(j = 0; j < SIZE_ROW; j++)
    {
      printf("%c ", table[i][j].current ? '*' : '.');
    }
    printf("\n");
  }
  printf("\n\n");
}
