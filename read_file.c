#include "header.h"

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
    int state, c = 0, r = 0, i = 0, j = 0;

    fp = fopen("gol_start.txt", "r");

    if (fp == NULL)
    {
        printf("File not found. Using a random start situation\n");
        for(i = 0; i < SIZE_COL; i++)
        {
            for(j = 0; j < SIZE_ROW; j++) /*Write No File on the Map*/
                {   
                    /*N*/
                    table[2][21].current = 1;
                    table[3][21].current = 1;
                    table[4][21].current = 1;
                    table[5][21].current = 1;
                    table[6][21].current = 1;
                    table[2][22].current = 1;
                    table[3][23].current = 1;
                    table[4][24].current = 1;
                    table[5][25].current = 1;
                    table[6][26].current = 1;
                    table[2][27].current = 1;
                    table[3][27].current = 1;
                    table[4][27].current = 1;
                    table[5][27].current = 1;
                    table[6][27].current = 1;
                    /*O*/
                    table[2][31].current_second = 1;
                    table[2][30].current_second = 1;
                    table[3][29].current_second = 1;
                    table[3][32].current_second = 1;
                    table[4][29].current_second = 1;
                    table[4][32].current_second = 1;
                    table[5][29].current_second = 1;
                    table[5][32].current_second = 1;
                    table[6][31].current_second = 1;
                    table[6][30].current_second = 1;
                    /*F*/
                    table[12][2].current_second = 1;
                    table[13][2].current_second = 1;
                    table[14][2].current_second = 1;
                    table[15][2].current_second = 1;
                    table[16][2].current_second = 1;
                    table[12][3].current_second = 1;
                    table[12][4].current_second = 1;
                    table[12][5].current_second = 1;
                    table[14][3].current_second = 1;
                    /*I*/
                    table[12][7].current_second = 1;
                    table[13][7].current_second = 1;
                    table[14][7].current_second = 1;
                    table[15][7].current_second = 1;
                    table[16][7].current_second = 1;
                    /*L*/
                    table[12][9].current = 1;
                    table[13][9].current = 1;
                    table[14][9].current = 1;
                    table[15][9].current = 1;
                    table[16][9].current = 1;
                    table[16][10].current = 1;
                    table[16][11].current = 1;
                    table[16][12].current = 1;
                    /*E*/
                    table[12][14].current = 1;
                    table[13][14].current = 1;
                    table[14][14].current = 1;
                    table[15][14].current = 1;
                    table[16][14].current = 1;
                    table[12][15].current = 1;
                    table[12][16].current = 1;
                    table[12][17].current = 1;
                    table[14][15].current = 1;
                    table[16][15].current = 1;
                    table[16][16].current = 1;
                    table[16][17].current = 1;

                    
                }
        } 
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
            if (state == '1')
            {
                table[c][r].current = 1;
            }
            else if (state == '2')
            {
                table[c][r].current_second = 1;
            }
            r++;
        }
    }
    fclose(fp); 
}