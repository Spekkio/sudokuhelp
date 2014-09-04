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

/***********************/
/*Variable declarations*/
/***********************/

struct row {
  int * data[9];
  int lock;
  int error;
}row;

struct column {
  int * data[9];
  int lock;
  int error;
}column;

struct abox {
  int * data[9];
  int * lock[9];
  int error;
}abox;

#define C_NORMAL     1
#define C_ERROR      2
#define C_HIGHLIGHT  3
#define C_HIGHLIGHT2 4

#define X_POS 0
#define Y_POS 1

/*******************/
/*Global Variables */
/*******************/

extern struct row rows[9];
extern struct column columns[9];
extern struct abox boxes[9];

extern int cpos_x, cpos_y;

extern int data[9][9];

/*positions of the numbers on the screen*/
extern int pos[9][9][2];

extern int help[9];
extern int complete[9];
extern int highlight[9];
extern int lock[9];
