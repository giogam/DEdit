#ifndef util_h__
#define util_h__


#include "base.h"

/* ------------------------------------------------------------------------- */
 /**
  *  funny macros to make the output of a C program more tasty
  *
  */

  #define FG_COLOR_BLACK   "\x1b[30m"   /* black text */
  #define FG_COLOR_RED     "\x1b[31m"		/* red text */
  #define FG_COLOR_GREEN   "\x1b[32m"		/* green text */
  #define FG_COLOR_YELLOW  "\x1b[33m"		/* yellow text */
  #define FG_COLOR_BLUE    "\x1b[34m"		/* blue text */
  #define FG_COLOR_MAGENTA "\x1b[35m"		/* magenta text */
  #define FG_COLOR_CYAN    "\x1b[36m"		/* cyan text */
  #define FG_COLOR_WHITE   "\x1b[37m"		/* white text */
  #define BG_COLOR_BLACK   "\x1b[40m"		/* black background */
  #define BG_COLOR_RED     "\x1b[41m"		/* red background */
  #define BG_COLOR_GREEN   "\x1b[42m"		/* green background */
  #define BG_COLOR_YELLOW  "\x1b[43m"		/* yellow background */
  #define BG_COLOR_BLUE    "\x1b[44m"		/* blue background */
  #define BG_COLOR_MAGENTA "\x1b[45m"		/* magenta background */
  #define BG_COLOR_CYAN    "\x1b[46m"		/* cyan background */
  #define BG_COLOR_WHITE   "\x1b[47m"		/* white background */
  #define COLOR_RESET      "\x1b[0m"		/* reset all configurations */

 /* ------------------------------------------------------------------------- */

/**
  * This functions appends a space character after the given string.
  *
  * @param char *str_a
  *
  *return char *
  */
char * str_cp( char *str_a);

/* ------------------------------------------------------------------------- */

#endif /* defined util_h__ */
