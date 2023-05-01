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
              30.4.2023 divided files

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

