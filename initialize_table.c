#include "header.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: intialize_table
 DESCRIPTION: setting up the array tables "current" and "future"
	Input: Global constants
	Output:
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
void initialize_table(struct cell table[SIZE_COL][SIZE_ROW])
{

    int i, j;

    for (i = 0; i < SIZE_COL; i++)
    {
        for (j = 0; j < SIZE_ROW; j++)
        {
            table[i][j].current = 0;
            table[i][j].future = 0;
            table[i][j].current_second = 0;
            table[i][j].future_second = 0;
            table[i][j].terrain = 0;     
        }
    }
}
