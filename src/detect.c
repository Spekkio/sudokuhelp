/** 
 * @file detect.c 
 * @author Copyright (C) 2014  Daniel Hedeblom <maxifoo@gmail.com>
 *
 * @todo Make a function to detect special occasions were there are
 *       2-3 empty cells in a row, that would draw a help bar for that row.
 *
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
#include "detect.h"
#include "sort.h"

/**
 * @brief Detect mistakes made on the sudoku board and print error messages.
 */
void detectErrors() {
  int sortr[9];
  int sortc[9];
  int sortb[9];

  int i,a;


  for(i=0;i<9;i++) {
    dataSort(rows[i].data, &sortr[0]);
    dataSort(columns[i].data, &sortc[0]);
    dataSort(boxes[i].data, &sortb[0]);

    rows[i].error=0;
    columns[i].error=0;
    boxes[i].error=0;

    /*detect duplicate number*/
    for(a=0;a<(9-1);a++) {

      /*Rows*/
      if(sortr[a]!=0) {
	if(sortr[a]==sortr[a+1]) {
	  rows[i].error=1;
	} else {
	  if(rows[i].error==0)
	    rows[i].error=0;
	}
      }

      /*Column*/
      if(sortc[a]!=0) {
	if(sortc[a]==sortc[a+1]) {
	  columns[i].error=1;
	} else {
	  if(columns[i].error==0)
	    columns[i].error=0;
	}
      }

      /*Box*/
      if(sortb[a]!=0) {
	if(sortb[a]==sortb[a+1]) {
	  boxes[i].error=1;
	} else {
	  if(boxes[i].error==0)
	    boxes[i].error=0;
	}
      }
    }
  }
}
