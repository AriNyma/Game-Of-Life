#include "header.h"

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/

int main()
{
    initscr(); /* initialize ncurses*/
    cbreak(); /* disable line buffering*/
    noecho(); /* don't echo input characters*/
    clear(); /* clear the screen*/
    struct cell table [SIZE_COL][SIZE_ROW];

    initialize_table(table);

    char state_c[SIZE_COL];
    read_map(table, state_c);
    read_file(table, state_c);
    
    int i;

    for (i = 0; i < 100; i++)
    {
        show_current_generation(table);
        future_generation(table);  
    }
    
    endwin(); /* end ncurses*/
    return 0;
} /* end of main */