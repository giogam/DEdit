#ifndef matrix_t_h__
#define matrix_t_h__

#include "base.h"
#include "edit.h"

/* ------------------------------------------------------------------------- */

/**
  * function that allocates a matrix of n_rows and n_cols
  *
  * @param int n_rows
  * @param int n_cols
  *
  * @return matrix_t
  */
matrix_t matrix_alloc( int n_rows , int n_cols );

/* ------------------------------------------------------------------------- */

/**
  * function that deallocates  the matrix
  *
  * @param matrix_t matrix
  * @param int n_rows
  *
  * @return void
  */
void matrix_clean( matrix_t matrix , int n_rows);

/* ------------------------------------------------------------------------- */

/**
  * function that initializes a row of a matrix with a value
  *
  * @param matrix_t  matrix
  * @param int val
  * @param int row
  * @param int n_cols
  *
  * @return void
  */
void matrix_set_row(matrix_t  matrix , int val , int row , int n_cols);

/* ------------------------------------------------------------------------- */

/**
  * function that initializes a column of a matrix with a value
  *
  * @param matrix_t  matrix
  * @param int val
  * @param int col
  * @param int n_rows
  *
  * @return void
  */
void matrix_set_column(matrix_t matrix , int val , int col , int n_rows);

/* ------------------------------------------------------------------------- */

/**
  * function that prints the contentt of a matrix. It provides two ways:
  * - cost == 1 (prints the cost matrix)
  * - cost == 0 (prints the parent matrix)
  *
  * @param char *a
  * @param char *b
  * @param int cost
  * @param matrix_t  matrix
  *
  * @return void
  */
void matrix_print(char *a , char *b , int cost ,matrix_t  matrix);

/* ------------------------------------------------------------------------- */

#endif /* defined matrix_t_h__ */
