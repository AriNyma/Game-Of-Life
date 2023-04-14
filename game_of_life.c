/***************************************************************************
 *   Copyright (C) 2023 by Ari Nyman                                       *
 *   e2203051@edu.vamk.fi                                                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************

 1.  NAME
        game_of_life

 2.  DESCRIPTION
        Program switches the "status" of a center node in a grid according the situation next to it.

        If the node has 4 or more active nodes adjacent to it then the center node will deactivate
        Also if the "neigbourhood" has 1 or less active nodes the node will deactivate
        In the case there are 3 active nodes the node will activate
        and in the case there are 2 active nodes the node will not change

 3.  VERSIONS
       Original:
         1.4.2023 Arny

       Version history:

**********************************************************************/

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
/* Control flags */

/* Global constants */
#define SIZE_ROW 10
#define SIZE_COL 10

/* Global variables */

/* Global structures */
struct cell
{
  int current;    /*starting situation, shown on screen*/
  int future;     /*upcomming situation*/
};

/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
int count_neighbours(struct cell table[SIZE_COL][SIZE_ROW], int x, int y);
//void read_file(struct cell table[SIZE_COL][SIZE_ROW], char )
void draw_table(struct cell table[SIZE_COL][SIZE_ROW]);
void show_current_generation(struct cell table[SIZE_COL][SIZE_ROW]);
void future_generation(struct cell table[SIZE_COL][SIZE_ROW]);

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/

int main()
{
  struct cell table [SIZE_COL][SIZE_ROW];

  draw_table(table);
  show_current_generation(table);
  int i;

  for (i = 0; i < 10; i++)
  {
    future_generation(table);
    show_current_generation(table);
  }
  return 0;
} /* end of main */

/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/


/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: draw_table
 DESCRIPTION: setting up the array tables for current random/set for future null
	Input:
	Output:
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
void draw_table(struct cell table[SIZE_COL][SIZE_ROW])
{
  srand(time(NULL));
  int i, j;
  
  for(i = 0; i < SIZE_COL; i++)
  {
    for(j = 0; j < SIZE_ROW; j++)
    {
      table[i][j].current = rand() % 2;
      table[i][j].future = 0;
    }
  }
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: count_neighbours
 DESCRIPTION: counting the neighbours of a node
	Input:
	Output:
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
int count_neighbours(struct cell table[SIZE_COL][SIZE_ROW], int x, int y) // määrittele alue tarkemmin ja poista keskimmäinen solu laskennasta
{
  /*reunojen rajaaminen pois: määritellään reuna-alueet eli esim i = 0 tai i = SIZE_COL-1, niin silloin table.future[i][j] = table.current[i][j]*/

  int count = 0, i, j;

  for(i = -1; i < 2; i++)
  {
    for(j = -1; j < 2; j++)
    {
      if(table[i][j].current == 1)
      {
        /*taulukon pyörittäminen: kun i = 0 niin viereinen (vasemmalla oleva solu on i + leveys -1)
        kun i = "max" oikealla oleva solu on i - leveys + 1. 2+10-1=11*/
        count ++;
      }
    }
  }
  count -= table[y][x].current; //xy toisin päin koska rivit ja saraakkeet on ilmoitettu myös toisin päin
  return count;
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: current_generation
 DESCRIPTION: print out the current table with the active and deactive nodes
	Input:
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

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: next_generation
 DESCRIPTION: creating the next generation according the current generation
	Input:
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
