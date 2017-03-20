#include "../include/matrix_t.h"

matrix_t matrix_alloc( int n_rows , int n_cols )
{
  matrix_t m;
  int i;

    m = ( struct m_bucket **) malloc( (n_rows  * sizeof(  struct m_bucket  * )));

    for(i=0 ; i < n_rows ; i++ )
    {
      m[i] = ( struct m_bucket *) malloc( (n_cols * sizeof(  struct m_bucket )));
    }

  return m;
}


void matrix_clean( matrix_t matrix , int n_rows)
{
  int i;

    for(i = 0 ; i < n_rows  ; i++)
    {
      free( ( matrix )[i]);
    }

    free( ( matrix ) );
}


void matrix_set_row(matrix_t  matrix , int val , int row , int n_cols)
{
  int i;

    for(i = 0 ; i < n_cols ; i++)
    {
      matrix[row][i].cost = val;

      if ((row  == 0) && ( i == 0 ))
        matrix[row][i].parent =  -1;
      else
        matrix[row][i].parent = INSERT;
      val++;
    }

}


void matrix_set_column(matrix_t matrix , int val , int col , int n_rows)
{
  int i;

    for(i = 0 ; i < n_rows ; i++)
    {
      matrix[i][col].cost = val;

      if ((col  == 0) && ( i == 0 ))
        matrix[i][col].parent =  -1;
      else
        matrix[i][col].parent = DELETE;

      val++;
    }

}


void matrix_print(char *a , char *b , int cost ,matrix_t  matrix)
{
  int len_s1 = strlen(a);
  int len_s2 = strlen(b);
  int i;
  int j;

  printf(BG_COLOR_CYAN "   " COLOR_RESET);
  for (i = 0 ; i < len_s2; i++)
  {
      if((i % 2) == 0) printf(BG_COLOR_CYAN FG_COLOR_BLACK"  %c" COLOR_RESET ,b[i] );
      else printf(BG_COLOR_GREEN  FG_COLOR_BLACK"  %c" COLOR_RESET ,b[i] );

  }
  printf("\n");

  for (i = 0; i < len_s1; i++)
  {
    if((i % 2) == 0) printf(BG_COLOR_CYAN FG_COLOR_BLACK "%c: " COLOR_RESET ,a[i]);
    else  printf(BG_COLOR_GREEN  FG_COLOR_BLACK "%c: " COLOR_RESET ,a[i]);

    for (j = 0; j < len_s2; j++)
    {
      if (cost == 1)
      {
        if((i % 2) == 0) printf(BG_COLOR_CYAN FG_COLOR_WHITE" %2d"COLOR_RESET,matrix[i][j].cost);
        else printf(BG_COLOR_GREEN FG_COLOR_BLACK" %2d"COLOR_RESET,matrix[i][j].cost);
      }

      else
      {
        if((i % 2) == 0) printf(BG_COLOR_CYAN FG_COLOR_WHITE" %2d"COLOR_RESET,matrix[i][j].parent);
        else printf(BG_COLOR_GREEN FG_COLOR_BLACK" %2d"COLOR_RESET,matrix[i][j].parent);
      }

    }
    printf("\n");
  }
printf("\n");
}
