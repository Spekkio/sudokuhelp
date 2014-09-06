/** 
 * @file draw.h
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

void printRows();
void highlightRow(const int n);
void highlightColumn(const int n);
void highlightBox(const int n, const t_color color, const int avoid_num);
void mvChangeColor(const int y, const int x, const t_color color);
int yxisChar(const int y, const int x, const int c);
void drawHelpGuides();

