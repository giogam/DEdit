#ifndef base_h__
#define base_h__

#include <stdio.h>
#if defined(__APPLE__)
  #include <malloc/malloc.h>
#else
  #include <malloc.h>
#endif
#include <stdlib.h>
#include <string.h>

/* ------------------------------------------------------------------------- */

/**
  *  It is composed of two integer values
  */
struct m_bucket
{
  int cost;
  int parent;
};

/* ------------------------------------------------------------------------- */

/**
  *   typedef for covenience
  */
typedef  struct m_bucket **  matrix_t;

/* ------------------------------------------------------------------------- */

#endif /* defined base_h__ */
