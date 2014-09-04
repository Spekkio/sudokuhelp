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
#include <string.h>
#include <config.h>
#include "globals.h"
#include "draw.h"
#include "detect.h"
#include "setup.h"
#include "sort.h"

/***********************/
/*Function declarations*/
/***********************/
void printHelp();
void dataSort(int * data[9], int sort[9]);

/*******************/
/*Global Variables */
/*******************/
struct row rows[9];
struct column columns[9];
struct abox boxes[9];

int cpos_x, cpos_y;

int data[9][9] =
{
  {0,7,0, 0,4,2, 0,0,3},
  {0,5,2, 0,0,8, 0,4,7},
  {0,0,0, 1,3,0, 0,2,0},

  {7,8,0, 0,0,0, 0,0,6},
  {0,0,6, 2,0,9, 8,0,0},
  {2,0,0, 0,0,0, 0,5,4},

  {0,1,0, 0,8,4, 0,0,0},
  {8,6,0, 7,0,0, 9,3,0},
  {9,0,0, 3,6,0, 0,1,0}
};

/*positions of the numbers on the screen*/
int pos[9][9][2];

int help[9] = {0,0,0,0,0,0,0,0,0};
int complete[9] = {0,0,0,0,0,0,0,0,0};
int highlight[9] = {0,0,0,0,0,0,0,0,0};
int lock[9] = {0,0,0,0,0,0,0,0,0};

/***********/
/*Functions*/
/***********/
void printHelp()
{
  int i=2;
  mvprintw(i++, 25, "Commands");
  mvprintw(i++, 25, "i: Highlight number.");
  mvprintw(i++, 25, "h: Help guides on number.");
  mvprintw(i++, 25, "d,x,0: Delete a number.");
  mvprintw(i++, 25, "");

}

int args(int argc, char **argv)
{
  int i;

  for(i=0;i<argc;i++) {

    if(!strncmp(argv[i],"--help",7))
      {
#ifdef HAVE_PRINTF
	printf("\n    --version    display version.");
	printf("\n    --help       display this help.");
	printf("\n    --about      about this program.");
	printf("\n");
#endif
	return 1;
      }
    else if(!strncmp(argv[i],"--version",9))
      {
#ifdef HAVE_PRINTF
	printf("\n%s.\n",PACKAGE_STRING);
	printf("\n");
#endif
	return 1;
      }
    else if(!strncmp(argv[i],"--about",7))
      {
#ifdef HAVE_PRINTF
	printf("\nA program for helping solving sudoku boards.");
	printf("\n");
#endif
	return 1;
      }

  }
  return 0;
}

int main(int argc, char **argv)
{
  int c, opt;

  if(args(argc,argv)) {
    return 0;
  }

  cpos_x=cpos_y=0;

  initscr();
  start_color();
  clear();
  noecho();

  keypad(stdscr, TRUE);

  setupPointers();
  calcPos();

  init_pair(C_NORMAL    , COLOR_WHITE, COLOR_BLACK);
  init_pair(C_ERROR     , COLOR_WHITE, COLOR_RED);    /*Error*/
  init_pair(C_HIGHLIGHT , COLOR_BLACK, COLOR_WHITE);  /*Highlight*/
  init_pair(C_HIGHLIGHT2, COLOR_WHITE, COLOR_BLUE);   /*Highlight 2*/
  init_pair(C_GREEN     , COLOR_WHITE, COLOR_GREEN); 

  clear();
  detectErrors();
  printRows();
  printHelp();
  drawHelpGuides();

  refresh();

  while(1) {

    if(cpos_y<0) cpos_y=0;
    if(cpos_y>8) cpos_y=8;

    if(cpos_x<0) cpos_x=0;
    if(cpos_x>8) cpos_x=8;

    move(pos[cpos_x][cpos_y][X_POS], pos[cpos_x][cpos_y][Y_POS]);

    c=getch();

    switch(c)
      {
      case KEY_UP:
	cpos_x--;
	break;

      case KEY_DOWN:
	cpos_x++;
	break;

      case KEY_LEFT:
	cpos_y--;
	break;

      case KEY_RIGHT:
	cpos_y++;
	break;

      case 'l':
	mvprintw(0,0,"Lock numbers: ");
	refresh();
	opt=getchar();
	clear();

	if(opt>=(0+48) && opt<=(9+48)) {
	  lock[opt-48] = !lock[opt-48];
	  /*mvprintw(0,0,"Highlighting: %i",opt-48);*/
	}
	break;

      case 'i':
	mvprintw(0,0,"Highlight number: ");
	refresh();
	opt=getchar();
	clear();

	if(opt>=(0+48) && opt<=(9+48)) {
	  highlight[opt-48] = !highlight[opt-48];
	  /*mvprintw(0,0,"Highlighting: %i",opt-48);*/
	}
	break;

      case 'h':
	mvprintw(0,0,"Help bars on number: ");
	refresh();
	opt=getchar();
	clear();

	if(opt>=(0+48) && opt<=(9+48)) {
	  help[opt-48] = !help[opt-48];
	  /*mvprintw(0,0,"Highlighting: %i",opt-48);*/
	}
	break;

      case 'd':
      case 'x':
      case KEY_DL:
	data[cpos_x][cpos_y] = 0;
	break;

      default:
	break;
      }

    if(c>=(0+48) && c<=(9+48)) {
      data[cpos_x][cpos_y] = c-48;
    }

    if(c=='q') {
      endwin();
      break;
    }

    clear();
    detectErrors();
    printRows();
    printHelp();
    drawHelpGuides();
    refresh();

  }

  return 0;
}
