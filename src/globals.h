/** 
 * @file globals.h
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

/***********************/
/*Variable declarations*/
/***********************/

/**
 * @brief The row structure
 */
struct row {
  int * data[9]; /*!< @brief Pointers to the numbers on the row */
  int lock;      /*!< @brief Unused */
  int error;     /*!< @brief Unused */
};

/**
 * @brief The column structure
 */
struct column {
  int * data[9];  /*!< @brief Pointers to the numbers in the column */
  int lock;       /*!< Unused */
  int error;      /*!< Unused */
};

/**
 * @brief The box structure
 */
struct abox {
  int * data[9]; /*!< @brief Pointers to the numbers in the box. */
  int * lock[9]; /*!< @brief Unused */
  int error;     /*!< @brief Unused */
};

/**
 * @brief ID numbers for the colors used on screen.
 * @todo Decide better naming for C_GREEN and C_HIGHLIGHT2
 */
enum color {
  C_NORMAL,
  C_ERROR,
  C_HIGHLIGHT,
  C_HIGHLIGHT2,
  C_GREEN
};

/**
 * @brief type definition of color ID's
 */
typedef enum color t_color;

#define X_POS 0 /*!< @brief used by \link pos pos \endlink */
#define Y_POS 1 /*!< @brief used by \link pos pos \endlink */

#define EMPTY_CHAR   '_' /*!< @brief Characte on free space */

/*******************/
/*Global Variables */
/*******************/

extern struct row rows[9];
extern struct column columns[9];
extern struct abox boxes[9];

extern int cpos_x, cpos_y;

extern int data[9][9];
extern int lock[9][9];

extern int pos[9][9][2];

extern int help[9];
extern int complete[9];
extern int highlight[9];
