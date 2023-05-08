#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: read_file
 DESCRIPTION: Sets up new alive cells from a external file
	Input: Global constants
	Output: 
  Used global variables:
 REMARKS when using this function: Does not check if file rows and columns
 match the given global constants
*********************************************************************/

void read_file(struct cell table[SIZE_COL][SIZE_ROW], char state_c[SIZE_COL])
{
  srand(time(NULL));
  FILE *fp;
  int state, c=0, r=0, i=0, j=0;

  fp = fopen("gol_start.txt", "r");

  if (fp == NULL)
  {
    printf("File not found. Using a random start situation\n");
    for(i = 0; i < SIZE_COL; i++)
    {
    for(j = 0; j < SIZE_ROW; j++)
        {
        table[i][j].current = rand() % 2;
        }
    } 
  }
  else
  {
    while((state = fgetc(fp)) != EOF)
    {
        if (state == '\n')
        {
        c++;
        r = 0;
        }
        else
        {
        if(state == '1')
        {
            table[c][r].current = 1;
        }
        else
        {
            table[c][r].current = 0;
        }
        r++;
        }
    }
  }
  fclose(fp);
}
  

