#include "../include/base.h"
#include "../include/matrix_t.h"
#include "../include/edit.h"
#include "../include/utils.h"


int main(int argc, char **argv)
{
/*
	char *usage = "Usage edit_d < String1 > < String 2 >";

	if((argc < 2 )|| (argc > 2))
	{
		printf("%s", usage);
		return -1;
	}
*/
	int a;

  char *str_a = str_cp(argv[1]);
	char *str_b = str_cp(argv[2]);

 	int i = strlen(str_a);
	int j = strlen(str_b);

	printf(FG_COLOR_CYAN"######################################" COLOR_RESET "\n");
	printf(FG_COLOR_CYAN "#" COLOR_RESET);
	printf(FG_COLOR_YELLOW "Wellcome to EDist calculator. Enjoy!" COLOR_RESET );
	printf(FG_COLOR_CYAN "#" COLOR_RESET "\n");
	printf(FG_COLOR_CYAN"######################################" COLOR_RESET "\n\n");

	matrix_t D = NULL;

		printf(FG_COLOR_CYAN "Calculating the Edit distance of: [%s]  [%s] " COLOR_RESET "\n\n",argv[1] ,argv[2]);

		D = matrix_alloc( i , j );

		matrix_set_row(D,0,0,j);
		matrix_set_column(D,0,0,i);


	a = edit_distance( str_a , str_b , D );

	printf(FG_COLOR_WHITE BG_COLOR_RED "Cost Matrix" COLOR_RESET "\n" );

	matrix_print(str_a , str_b, 1 ,D);

	printf(FG_COLOR_WHITE BG_COLOR_RED"Parent Matrix" COLOR_RESET "\n");
	matrix_print(str_a , str_b, 0  ,D);

	printf(FG_COLOR_WHITE BG_COLOR_RED"Edit Operations" COLOR_RESET "\n");
	reconstruct_path(str_a , str_b ,(i-1) , (j-1) , D);

	printf("\n");
	printf(FG_COLOR_WHITE BG_COLOR_RED"Edit Distance:" COLOR_RESET );
	printf(BG_COLOR_GREEN FG_COLOR_WHITE " %d " COLOR_RESET "\n",a);


	matrix_clean(D , i);
  free(str_a);
  free(str_b);

	return 0;
}
