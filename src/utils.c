#include "../include/utils.h"



 char * str_cp(  char *str_a)
 {
   char * str = (char *) malloc((strlen(str_a) + 1) * sizeof(char));
   int i  = 1;
   int j  = 0;

    str[0]= ' ';
    while(i <= strlen(str_a) )
    {
      str[i] = str_a[j];
      i++;
      j++;
    }

  str[i] = '\0';

  return str;
}
