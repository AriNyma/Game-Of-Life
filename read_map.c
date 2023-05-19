#include "header.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: read_map
 DESCRIPTION: Sets up new world
	Input: Global constants
	Output: 
  Used global variables:
 REMARKS when using this function: Does not check if file rows and columns
 match the given global constants
*********************************************************************/

void read_map(struct cell table[SIZE_COL][SIZE_ROW], char state_c[SIZE_COL])
{
    FILE *fp;
    int state, c = 0, r = 0;

    fp = fopen("gol_map.txt", "r");

    if (fp == NULL)
    {
        printf("File not found\n");
        exit(1);
    }
    while ((state = fgetc(fp)) != EOF)
    {
        if (state == '\n')
        {
            c++;
            r = 0;
        }
        else
        {
            if (state == 'd')
            {
                table[c][r].terrain = 0; /* Desert */
            }
            else if (state == 'p')
            {
                table[c][r].terrain = 1; /* Pit Hole */
            }
            else if (state == 'f')
            {
                table[c][r].terrain = 2; /* Forest */
            }
            else if (state == 't')
            {
                table[c][r].terrain = 3; /* Fortress */
            }

            r++;
        }
    }
    fclose(fp); 
}


