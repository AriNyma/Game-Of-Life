#include "header.h"

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: future_generation
 DESCRIPTION: creating the next generation according the current generation
	Input: Global constants and count_neighbours function result
	Output:
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
void future_generation(struct cell table[SIZE_COL][SIZE_ROW])
{
    int i, j;

    for (i = 0; i < SIZE_COL; i++)
    {
        for (j = 0; j < SIZE_ROW; j++)
        {
            int neighbours = count_neighbours(table, i, j);
            int hostile = count_hostiles(table, i, j);
            int terrain = table[i][j].terrain;

            if (terrain == 0) /* Desert */
            {
                /*first population*/
                if (table[i][j].current == 0)
                {
                    if (neighbours == 3)
                    {
                        table[i][j].future = 1;
                    }
                    else
                    {
                        table[i][j].future = 0;
                    }
                }
                else if (table[i][j].current == 1)
                {
                    if (neighbours < 2 || neighbours > 3)
                    {
                        table[i][j].future = 0;
                    }
                    else
                    {
                        table[i][j].future = 1;
                    }
                }
                /*second population*/
                if (table[i][j].current_second == 0)
                {
                    if (hostile >= 2 && hostile <= 4)
                    {
                        table[i][j].future_second = 1;
                    }
                    else
                    {
                        table[i][j].future_second = 0;
                    }
                }
                else if (table[i][j].current_second == 1)
                {
                    if (hostile < 2 || hostile > 4)
                    {
                        table[i][j].future_second = 0;
                    }
                    else
                    {
                        table[i][j].future_second = 1;
                    }
                }
              
            }
            else if (terrain == 1) /* Pit Hole */
            {
                table[i][j].future = 0; /* Creatures fall into pit hole and die */
                table[i][j].future_second = 0;
            }
            else if (terrain == 2) /* Forrest */
            {
                /*first population*/
                if (table[i][j].current == 0)
                {
                    if (neighbours >= 2 && neighbours <= 4)
                    {
                        table[i][j].future = 1;
                    }
                    else
                    {
                        table[i][j].future = 0;
                    }
                }
                else if (table[i][j].current == 1)
                {
                    if (neighbours < 2 || neighbours > 5)
                    {
                        table[i][j].future = 0;
                    }
                    else
                    {
                        table[i][j].future = 1;
                    }
                }
                /*second population*/
                if (table[i][j].current_second == 0)
                {
                    if (hostile == 3)
                    {
                        table[i][j].future_second = 1;
                    }
                    else
                    {
                        table[i][j].future_second = 0;
                    }
                }
                else if (table[i][j].current_second == 1)
                {
                    if (hostile < 2 || hostile > 3)
                    {
                        table[i][j].future_second = 0;
                    }
                    else
                    {
                        table[i][j].future_second = 1;
                    }
                }                
            }
            else if (terrain == 3) /* Fortress */
            {
                if (table[i][j].current == 0)
                {
                    if (neighbours >= 3)
                    {
                        table[i][j].future = 1; /* Own easily go over the wall */
                    }
                    else
                    {
                        table[i][j].future = 0;
                    }
                } 
            }
        }
    }
     for (i = 0; i < SIZE_COL; i++)
    {
        for (j = 0; j < SIZE_ROW; j++)
        {
            table[i][j].current = table[i][j].future;
            table[i][j].current_second = table[i][j].future_second;
        }
    } 

}