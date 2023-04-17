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
void read_file(struct cell table[SIZE_COL][SIZE_ROW], char state_c[SIZE_COL]);
void intialize_table(struct cell table[SIZE_COL][SIZE_ROW]);
void show_current_generation(struct cell table[SIZE_COL][SIZE_ROW]);
void future_generation(struct cell table[SIZE_COL][SIZE_ROW]);

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/

int main()
{
  struct cell table [SIZE_COL][SIZE_ROW];

  intialize_table(table);

  char state_c[SIZE_COL];
  read_file(table, state_c);

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
 NAME: intialize_table
 DESCRIPTION: setting up the array tables "current" and "future"
	Input: Global constants
	Output:
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
void intialize_table(struct cell table[SIZE_COL][SIZE_ROW])
{
  int i, j;

  for(i = 0; i < SIZE_COL; i++)
  {
    for(j = 0; j < SIZE_ROW; j++)
    {
      table[i][j].current = 0;
      table[i][j].future = 0;
    }
  }

}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: count_neighbours
 DESCRIPTION: counting the alive neighbours of a node
	Input: Global constants
	Output: Count of alive neighbour cells
  Used global variables:
 REMARKS when using this function:
*********************************************************************/
int count_neighbours(struct cell table[SIZE_COL][SIZE_ROW], int x, int y)
{
  int count = 0, i, j;

  for(i = -1; i < 2; i++)
  {
    for(j = -1; j < 2; j++)
    {
      //wrapping the array table around so the edges can be included in the count
      int col = (x + i + SIZE_COL) % SIZE_COL;
      int row = (y + j + SIZE_ROW) % SIZE_ROW;

      if(table[col][row].current == 1)
      {
        count ++;
      }
    }
  }
  count -= table[x][y].current;
  return count;
}

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

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: next_generation
 DESCRIPTION: creating the next generation according the current generation
	Input: Global constants and count_neighbours function result
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
  FILE *fp;
  int state, c=0, r=0;

  fp = fopen("gol_start.txt", "r");

  if (fp == NULL)
  {
    printf("File not found\n");
    exit(1);
  }

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
  fclose(fp);
}
  

