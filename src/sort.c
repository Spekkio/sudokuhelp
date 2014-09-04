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
#include "sort.h"

void dataSort(int * data[9], int sort[9])
{
  int i,temp,sorted=0;

  for(i=0;i<9;i++) {
    sort[i] = *data[i];
  }

  i=0;
  while(sorted==0) {
    sorted=1;
    for(i=0;i<(9-1);i++) {
      if(sort[i] > sort[i+1]) {
	temp = sort[i];
	sort[i] = sort[i+1];
	sort[i+1] = temp;
	sorted=0;
      }
    }
  }
}
