/** 
 * @file sort.c 
 * @brief Just a very simple sorting algoritm for arrays.
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

#include <stdlib.h>
#include "globals.h"
#include "sort.h"

/**
 * Compare function to be used by qsort()
 */
int cmp(const void * a, const void * b)
{
  int f = *(int *)a;
  int s = *(int *)b;

  if(f<s)
    return -1;
  else if(f==s)
    return 0;
  else /*if(f>s)*/
    return 1;

}

/**
 * Sorts an array using builtin qsort algorithm.
 * 
 * @param data this is the input array
 * @param sort output array where the result is stored
 */
void dataSort(int * data[9], int sort[9])
{
  int i;
  for(i=0;i<9;i++) {
    sort[i] = *data[i];
  }
  qsort(&sort[0], 9, sizeof(int), cmp);
}
