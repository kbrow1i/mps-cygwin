/*  ==== TEST LIBRARY ====
 *
 *  $HopeName: !testlib.c(MM_dylan_sunflower.1) $
 *
 *  Copyright (C) 1995 Harlequin Group, all rights reserved
 *
 *  This is a library of functions that may be of use to unit tests.
 *
 *  Notes
 */

#include "mps.h"
#include "testlib.h"
#ifdef MPS_OS_SU
#include "ossu.h"
#endif

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


/* I nabbed it from "ML for the Working Programmer"
 * Originally from:
 * Stephen K Park & Keith W Miller (1988). Random number generators:
 * good one are to find.  Communications of the ACM, 31:1192-1201
 */
unsigned long rnd(void)
{
  static unsigned long seed = 1;
  double s;
  s = seed;
  s *= 16807.0;
  s = fmod(s, 2147483647.0);  /* 2^31 - 1 */
  seed = (unsigned long)s;
  return seed;
}

void die(mps_res_t res, const char *s)
{
  if(res != MPS_RES_OK)
  {
    fprintf(stderr, "%s: %d\n", s, res);
    exit(1);
  }
}

