#ifndef levenshtein_h__
#define levenshtein_h__

#include "base.h"
#include "utils.h"
#include "matrix_t.h"

/* ------------------------------------------------------------------------- */

#define MATCH           0  /* MATCH value */
#define INSERT          1  /* INSERT value */
#define DELETE          2  /* DELETE value */ 

/* ------------------------------------------------------------------------- */

/**
  * Function that performs a match of two given characters.
  * if a == b it returns 0 otherwise , if the two characters
  * do not match , it returns 1.
  *
  * @param char a
  * @param char b
  *
  * @return int
  */
int match(char a , char b);

/* ------------------------------------------------------------------------- */

/**
  * Function that prints on screen an edit operation of the form:
  * - S Subst a with b (where a and b are two characters)
  * - M No edit needed
  *
  * @param char *s1
  * @param char *s2
  * @param int i
  * @param int j
  *
  * @return void
  */
void match_out(char *s1, char *s2,int i, int j);

/* ------------------------------------------------------------------------- */

/**
  * Function that prints on screen an edit operation of the form:
  * - I Insert a (where a is a character)
  *
  * @param char *t
  * @param int j
  *
  * @return void
  */
void insert_out(char *t, int j);

/* ------------------------------------------------------------------------- */

/**
    * Function that prints on screen an edit operation of the form:
    * - D Delete a (where a is a character)
    *
    * @param char *s
    * @param int i
    *
    * @return void
    */
void delete_out(char *s, int i);

/* ------------------------------------------------------------------------- */

/**
  * Function that that recursively reconstructs the edit operations path.
  * It also produces a textual list as output.
  *
  * @param char *s1
  * @param char *s2
  * @param int i
  * @param int j
  * @param matrix_t matrix
  *
  * @return void
  */
void reconstruct_path(char *s1, char *s2 , int i, int j , matrix_t matrix);

/* ------------------------------------------------------------------------- */

/**
  * Function that calculates the edit distance of two strings.
  *
  * @param char *s1
  * @param char *s2
  * @param matrix_t matrix
  *
  * @return int
  */
int levenshtein_distance( char *s1 , char *s2 ,matrix_t  matrix );

/* ------------------------------------------------------------------------- */

#endif /* defined levenshtein_h__ */
