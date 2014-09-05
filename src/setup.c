/** 
 * @file setup.c
 * @brief Contains setup routines that runs once.
 */

/**************************************************************************

    Sudoku Help, A program to help solve sudoku puzzles
    Copyright (C) 2014  Daniel Hedeblom <maxifoo@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

**************************************************************************/

#include "globals.h"
#include "setup.h"

/**
 * Setup pointers for the row, columns and boxes structures.
 */
void setupPointers()
{
  int i,c;

  for(i=0;i<9;i++) {
    rows[i].lock=0;
    columns[i].lock=0;

    for(c=0;c<9;c++) {
      rows[i].data[c] = &data[i][c];
      columns[i].data[c] = &data[c][i];
    }
  }

  /*Box 1*/
  boxes[0].data[0] = rows[0].data[0];
  boxes[0].data[1] = rows[0].data[1];
  boxes[0].data[2] = rows[0].data[2];
  boxes[0].data[3] = rows[1].data[0];
  boxes[0].data[4] = rows[1].data[1];
  boxes[0].data[5] = rows[1].data[2];
  boxes[0].data[6] = rows[2].data[0];
  boxes[0].data[7] = rows[2].data[1];
  boxes[0].data[8] = rows[2].data[2];

  /*Box 2*/
  boxes[1].data[0] = rows[0].data[3];
  boxes[1].data[1] = rows[0].data[4];
  boxes[1].data[2] = rows[0].data[5];
  boxes[1].data[3] = rows[1].data[3];
  boxes[1].data[4] = rows[1].data[4];
  boxes[1].data[5] = rows[1].data[5];
  boxes[1].data[6] = rows[2].data[3];
  boxes[1].data[7] = rows[2].data[4];
  boxes[1].data[8] = rows[2].data[5];

  /*Box 3*/
  boxes[2].data[0] = &data[0][6];
  boxes[2].data[1] = &data[0][7];
  boxes[2].data[2] = &data[0][8];
  boxes[2].data[3] = &data[1][6];
  boxes[2].data[4] = &data[1][7];
  boxes[2].data[5] = &data[1][8];
  boxes[2].data[6] = &data[2][6];
  boxes[2].data[7] = &data[2][7];
  boxes[2].data[8] = &data[2][8];

  /*Box 4*/
  boxes[3].data[0] = &data[3][0];
  boxes[3].data[1] = &data[3][1];
  boxes[3].data[2] = &data[3][2];
  boxes[3].data[3] = &data[4][0];
  boxes[3].data[4] = &data[4][1];
  boxes[3].data[5] = &data[4][2];
  boxes[3].data[6] = &data[5][0];
  boxes[3].data[7] = &data[5][1];
  boxes[3].data[8] = &data[5][2];

  /*Box 5*/
  boxes[4].data[0] = &data[3][3];
  boxes[4].data[1] = &data[3][4];
  boxes[4].data[2] = &data[3][5];
  boxes[4].data[3] = &data[4][3];
  boxes[4].data[4] = &data[4][4];
  boxes[4].data[5] = &data[4][5];
  boxes[4].data[6] = &data[5][3];
  boxes[4].data[7] = &data[5][4];
  boxes[4].data[8] = &data[5][5];

  /*Box 6*/
  boxes[5].data[0] = &data[3][6];
  boxes[5].data[1] = &data[3][7];
  boxes[5].data[2] = &data[3][8];
  boxes[5].data[3] = &data[4][6];
  boxes[5].data[4] = &data[4][7];
  boxes[5].data[5] = &data[4][8];
  boxes[5].data[6] = &data[5][6];
  boxes[5].data[7] = &data[5][7];
  boxes[5].data[8] = &data[5][8];

  /*Box 7*/
  boxes[6].data[0] = &data[6][0];
  boxes[6].data[1] = &data[6][1];
  boxes[6].data[2] = &data[6][2];
  boxes[6].data[3] = &data[7][0];
  boxes[6].data[4] = &data[7][1];
  boxes[6].data[5] = &data[7][2];
  boxes[6].data[6] = &data[8][0];
  boxes[6].data[7] = &data[8][1];
  boxes[6].data[8] = &data[8][2];

  /*Box 8*/
  boxes[7].data[0] = &data[6][3];
  boxes[7].data[1] = &data[6][4];
  boxes[7].data[2] = &data[6][5];
  boxes[7].data[3] = &data[7][3];
  boxes[7].data[4] = &data[7][4];
  boxes[7].data[5] = &data[7][5];
  boxes[7].data[6] = &data[8][3];
  boxes[7].data[7] = &data[8][4];
  boxes[7].data[8] = &data[8][5];

  /*Box 9*/
  boxes[8].data[0] = &data[6][6];
  boxes[8].data[1] = &data[6][7];
  boxes[8].data[2] = &data[6][8];
  boxes[8].data[3] = &data[7][6];
  boxes[8].data[4] = &data[7][7];
  boxes[8].data[5] = &data[7][8];
  boxes[8].data[6] = &data[8][6];
  boxes[8].data[7] = &data[8][7];
  boxes[8].data[8] = &data[8][8];

}

/**
 * Calculate the positions of the numbers on the screen
 * and store in the global matrix pos.
 * @sa pos
 */
void calcPos()
{
  int i,r;
  int x,y;

  x=y=0;

  for(i=0;i<9;i++)
    {
      x=0;
      for(r=0;r<9;r++)
	{
	  pos[i][r][X_POS] = y+2;
	  pos[i][r][Y_POS] = x+2;

	  x+=2;
	  if( (r % 3) == 2 ) {
	    x++;
	  }
	}
      y+=1;
      if( (i % 3) == 2 ) {
	y++;
      }
    }
}
