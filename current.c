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
    
    start_color(); /* enable color */
    init_pair(1, COLOR_RED, COLOR_BLUE); /* define a color pair for first population */
    init_pair(2, COLOR_BLUE, COLOR_RED); /* define a color pair for second population */
    init_pair(3, COLOR_MAGENTA, COLOR_YELLOW); /*desert*/
    init_pair(4, COLOR_YELLOW, COLOR_GREEN); /*forrest*/
    init_pair(5, COLOR_WHITE, COLOR_BLACK); /*pit*/
    init_pair(6, COLOR_WHITE, COLOR_CYAN); /*fort*/

    for (i = 0; i < SIZE_COL; i++)
    {
        for (j = 0; j < SIZE_ROW; j++)
        {
            if (table[i][j].current == 1 || table[i][j].current_second == 1)
            {
                if(table[i][j].current == 1)
                {
                attron(COLOR_PAIR(1));
                mvaddch(i, j, ' '); /* print a space with colorpair at position (i,j)*/
                attroff(COLOR_PAIR(1));
                }
                else if (table[i][j].current_second == 1)
                {
                    attron(COLOR_PAIR(2));
                    mvaddch(i, j, ' '); /* print a space with colorpair at position (i,j)*/
                    attroff(COLOR_PAIR(2));
                }
            }
            else if (table[i][j].terrain ==  0)
            {
                attron(COLOR_PAIR(3));
                mvaddch(i, j, ' '); /* print a space with colorpair at position (i,j)*/
                attroff(COLOR_PAIR(3));
            }
            else if(table[i][j].terrain ==  2)
            {
                attron(COLOR_PAIR(4));
                mvaddch(i, j, ' '); /* print a space with colorpair at position (i,j)*/
                attroff(COLOR_PAIR(4));
            }
            else if(table[i][j].terrain ==  1)
            {
                attron(COLOR_PAIR(5));
                mvaddch(i, j, ' '); /* print a space with colorpair at position (i,j)*/
                attroff(COLOR_PAIR(5));
            }
            else if(table[i][j].terrain ==  3)
            {
                attron(COLOR_PAIR(6));
                mvaddch(i, j, ' '); /* print a space with colorpair at position (i,j)*/
                attroff(COLOR_PAIR(6));
            }  
        } 
    }
    sleep(1);
    refresh();
}
