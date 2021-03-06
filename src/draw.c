/** 
 * @file draw.c 
 * @brief Functions for drawing the screen.
 * @author Copyright (C) 2014  Daniel Hedeblom <maxifoo@gmail.com>
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

#include <ncurses.h>
#include "globals.h"
#include "draw.h"

/**
 * @brief Prints the sudoku board
 */
void printRows()
{
  int i,r;
  char c[10];

  for(i=0;i<9;i++)
    {

      /* Some error detection */
      if(rows[i].error) {
	mvprintw(15,0,"Error at row %i",i);
      }
      if(columns[i].error) {
	mvprintw(16,0,"Error at column %i",i);
      }
      if(boxes[i].error) {
	mvprintw(17,0,"Error at box %i",i);
      }


      for(r=0;r<9;r++)
	{
	  sprintf(&c[0], "%i", *rows[i].data[r]);

	  if(c[0]=='0') c[0]=EMPTY_CHAR;

	  /* Detect if a number should be highlighted */
	  if( (c[0]-48)<=9 && (c[0]-48)>=1) {
	    if(highlight[c[0]-48-1]) {
	      attron(COLOR_PAIR(C_HIGHLIGHT));
	      attron(A_BOLD);
	    }
	  }

	  if(lock[i][r])
	    {
	      attron(A_BOLD);
	    }

	  mvprintw( pos[i][r][X_POS], pos[i][r][Y_POS] ,"%s",c);

	    attroff(A_BOLD);
	    attroff(COLOR_PAIR(C_HIGHLIGHT));
	}
    }
}


/**
 * @brief Highlight a row
 * @param n highlights row n
 * @todo Make is possible to choose color
 */
void highlightRow(const int n)
{
  int i;

  i=0;

  while(i<pos[n][8][Y_POS]-1) {
    mvChangeColor(pos[n][0][X_POS], pos[n][0][Y_POS]+i, C_HIGHLIGHT2);
    i++;
  }

}

/**
 * @brief Highlight a column
 * @param n highlights column n
 * @todo Make is possible to choose color
 */
void highlightColumn(const int n)
{
  int i;

  i=0;

  while(i<pos[8][n][X_POS]-1) {
    mvChangeColor(pos[0][n][X_POS]+i, pos[0][n][Y_POS], C_HIGHLIGHT2);
    i++;
  }
}

/**
 * @brief Highlight a box
 * @param n highlights box n
 * @param color color to use
 * @param avoid_num if set to 1, only highlight free cells. otherwise set to zero
 */
void highlightBox(const int n, const t_color color, const int avoid_num)
{
  int y,x;
  int cx,cy;

  x=y=0;
  cy=cx=0;

  switch(n)
    {
    case 0:
    case 1:
    case 2:
      while(y<=(pos[0][n*3+2][Y_POS]-pos[0][n*3][Y_POS])) { /*really is x dir*/
	x=0;
	while(x<=(pos[2][0][X_POS]-pos[0][0][X_POS])) { /*really is y dir*/

	  /*x,y was switched sometime*/
	  cy = pos[0][0][X_POS]+x;
	  cx = pos[0][n*3][Y_POS]+y;

	  if(avoid_num) {
	    if(yxisChar(cy, cx, EMPTY_CHAR))
	      {
		mvChangeColor(cy, cx, color);
	      }
	  } else
	    mvChangeColor(cy, cx, color);

	  x++;
	}
	y++;
      }
      break;

    case 3:
    case 4:
    case 5:
      while(y<=(pos[0][(n-3)*3+2][Y_POS]-pos[0][(n-3)*3][Y_POS])) { /*really is x dir*/
	x=0;
	while(x<=(pos[5][0][X_POS]-pos[3][0][X_POS])) { /*really is y dir*/

	  /*x,y was switched sometime*/
	  cy = pos[3][0][X_POS]+x;
	  cx = pos[0][(n-3)*3][Y_POS]+y;

	  if(avoid_num) {
	    if(yxisChar(cy, cx, EMPTY_CHAR))
	      {
		mvChangeColor(cy, cx, color);
	      }
	  } else
	    mvChangeColor(cy, cx, color);

	  x++;
	}
	y++;
      }
      break;

    case 6:
    case 7:
    case 8:
      while(y<=(pos[0][(n-6)*3+2][Y_POS]-pos[0][(n-6)*3][Y_POS])) { /*really is x dir*/
	x=0;
	while(x<=(pos[8][0][X_POS]-pos[6][0][X_POS])) { /*really is y dir*/

	  /*x,y was switched sometime*/
	  cy = pos[6][0][X_POS]+x;
	  cx = pos[0][(n-6)*3][Y_POS]+y;

	  if(avoid_num) {
	    if(yxisChar(cy, cx, EMPTY_CHAR))
	      {
		mvChangeColor(cy, cx, color);
	      }
	  } else
	    mvChangeColor(cy, cx, color);

	  x++;
	}
	y++;
      }
      break;

    default:
      break;
    }

}

/**
 * @brief Compare character at screen position x,y with c.
 * @param y position on the screen
 * @param x position on the screen
 * @param c character to check
 * @return Returns 1 if character on position x,y equals given character c.
 * @retval 0 given character does not match the character on x,y
 * @retval 1 given character matches the character on x,y
 */
int yxisChar(const int y, const int x, const int c)
{
  int cmp;
  move(y,x);
  cmp=inch();

  if(cmp==c) {
    return 1;
  } else return 0;

}

/**
 * @brief Change the color scheme of a pixel on screen
 * @param y y position on the screen
 * @param x x position on the screen
 * @param color color to use.
 */
void mvChangeColor(const int y, const int x, const t_color color)
{
  int c;
  move(y,x);
  c=inch();

  attron(COLOR_PAIR(color));
  printw("%c",c);
  attroff(COLOR_PAIR(color));
}

/**
 * @brief Draw all the help guides
 */
void drawHelpGuides()
{
  int i,s,d;

  for(i=0;i<9;i++) {

    highlightBox(i, C_GREEN, 1); /* mark free fields green */

    /*number i wants help guides*/
    if(help[i]==1) {

      for(s=0;s<9;s++){
	for(d=0;d<9;d++) {

	  /*look in rows*/
	  if(*rows[s].data[d]==i+1) {
	    highlightRow(s);
	  }

	  /*look in columns*/
	  if(*columns[s].data[d]==i+1) {
	    highlightColumn(s);
	  }

	  /*look in boxes*/
	  if(*boxes[s].data[d]==i+1) {
	    highlightBox(s, C_HIGHLIGHT2, 0);
	  }
	}
      }
    }
  }
}
