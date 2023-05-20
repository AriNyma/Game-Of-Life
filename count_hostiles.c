#include "header.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: count_hostiles
 DESCRIPTION: counting the alive neighbours of a node
	Input: Global constants
	Output: Count of alive neighbour cells
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
int count_hostiles(struct cell table[SIZE_COL][SIZE_ROW], int x, int y)
{
    int count = 0, i, j;

    for (i = -1; i < 2; i++)
    {
        for (j = -1; j < 2; j++)
        {
            /*wrapping the array table around so the edges can be included in the count*/
            int col = (x + i + SIZE_COL) % SIZE_COL;
            int row = (y + j + SIZE_ROW) % SIZE_ROW;

            if (table[col][row].current_second == 1)
            {
                count++;
            }
        }
    }
    count -= table[x][y].current_second;
    return count;
}
