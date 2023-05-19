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

enum {NONE, POP1, POP2, DES, FOR, PIT, FORT};

void show_current_generation(struct cell table[SIZE_COL][SIZE_ROW])
{
     int i, j;
    
    start_color(); /* enable color */
    init_pair(POP1, COLOR_RED, COLOR_BLUE); /* define a color pair for first population */
    init_pair(POP2, COLOR_BLUE, COLOR_RED); /* define a color pair for second population */
    init_pair(DES, COLOR_MAGENTA, COLOR_YELLOW); /*desert*/
    init_pair(FOR, COLOR_YELLOW, COLOR_GREEN); /*forrest*/
    init_pair(PIT, COLOR_WHITE, COLOR_BLACK); /*pit*/
    init_pair(FORT, COLOR_WHITE, COLOR_CYAN); /*fort*/

    for (i = 0; i < SIZE_COL; i++)
    {
        for (j = 0; j < SIZE_ROW; j++)
        {
            if (table[i][j].current == 1 || table[i][j].current_second == 1)
            {
                if(table[i][j].current == 1)
                {
                attron(COLOR_PAIR(POP1));
                mvaddch(i, j, ' '); /* print a space with colorpair at position (i,j)*/
                attroff(COLOR_PAIR(POP1));
                }
                else if (table[i][j].current_second == 1)
                {
                    attron(COLOR_PAIR(POP2));
                    mvaddch(i, j, ' '); /* print a space with colorpair at position (i,j)*/
                    attroff(COLOR_PAIR(POP2));
                }
            }
            else if (table[i][j].terrain ==  0)
            {
                attron(COLOR_PAIR(DES));
                mvaddch(i, j, ' '); /* print a space with colorpair at position (i,j)*/
                attroff(COLOR_PAIR(DES));
            }
            else if(table[i][j].terrain ==  2)
            {
                attron(COLOR_PAIR(FOR));
                mvaddch(i, j, ' '); /* print a space with colorpair at position (i,j)*/
                attroff(COLOR_PAIR(FOR));
            }
            else if(table[i][j].terrain ==  1)
            {
                attron(COLOR_PAIR(PIT));
                mvaddch(i, j, ' '); /* print a space with colorpair at position (i,j)*/
                attroff(COLOR_PAIR(PIT));
            }
            else if(table[i][j].terrain ==  3)
            {
                attron(COLOR_PAIR(FORT));
                mvaddch(i, j, ' '); /* print a space with colorpair at position (i,j)*/
                attroff(COLOR_PAIR(FORT));
            }  
        } 
    }
    sleep(1);
    refresh();
}
