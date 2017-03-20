#include "../include/edit.h"

int match(char a , char b)
{
   if(a == b) return 0;
    else return 1;
}

void match_out(char *s1, char *s2,int i, int j)
{
  if (s1[i] == s2[j])
  {

    printf(BG_COLOR_CYAN FG_COLOR_WHITE " M " COLOR_RESET);
    printf(BG_COLOR_GREEN  FG_COLOR_WHITE " Maintain [%c] " COLOR_RESET "\n",s1[i] );
  }
  else
  {
    printf(BG_COLOR_CYAN FG_COLOR_WHITE " S " COLOR_RESET);
    printf(BG_COLOR_GREEN  FG_COLOR_WHITE " Subst [%c] with [%c] " COLOR_RESET "\n",s1[i] , s2[j]);
  }
}

void insert_out(char *t, int j)
{
  printf(BG_COLOR_CYAN FG_COLOR_WHITE " I " COLOR_RESET);
  printf(BG_COLOR_GREEN  FG_COLOR_WHITE " Insert [%c]" COLOR_RESET "\n",t[j]);
}

void delete_out(char *s, int i)
{
  printf(BG_COLOR_CYAN FG_COLOR_WHITE " D " COLOR_RESET);
  printf(BG_COLOR_GREEN  FG_COLOR_WHITE" Delete [%c] " COLOR_RESET "\n",s[i]);
}

void reconstruct_path(char *s1, char *s2 , int i, int j , matrix_t matrix)
{
  if(matrix[i][j].parent == -1) return;


  if (matrix[i][j].parent == MATCH)
  {
    reconstruct_path(s1,s2,i-1,j-1,matrix);
    match_out(s1, s2, i, j);
    return;
  }

  if (matrix[i][j].parent == INSERT)
  {
    reconstruct_path(s1,s2,i,j-1,matrix);
    insert_out(s2, j);
    return;
  }

  if (matrix[i][j].parent == DELETE)
  {
    reconstruct_path(s1,s2,i-1,j,matrix);
    delete_out(s1 , i);
    return;
  }

}

int edit_distance( char *s1 , char *s2 ,matrix_t  matrix )
{
  int options[3];
  int len_s1 = strlen(s1);
  int len_s2 = strlen(s2);
  int res;
  int i;
  int j;
  int k;

    for(i = 1 ; i < len_s1 ; i++ )
    {
      for(j = 1 ; j < len_s2 ; j++)
      {
        options[MATCH]  = matrix[i-1][j-1].cost + match(s1[i],s2[j]);
        options[INSERT] = matrix[i][j-1].cost + 1;
        options[DELETE] = matrix[i-1][j].cost + 1;

        matrix[i][j].cost = options[MATCH];
        matrix[i][j].parent = MATCH;

        for (k = INSERT; k <= DELETE; k++)
        {
          if (options[k] < matrix[i][j].cost)
          {
            matrix[i][j].cost = options[k];
            matrix[i][j].parent = k;
          }
        }
      }

    }

    res = matrix[(len_s1-1)][(len_s2 -1)].cost;


  return res;
}
