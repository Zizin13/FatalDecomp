#include "userfns.h"
#include <math.h>
//-------------------------------------------------------------------------------------------------

double getdirection(double a1, double a2)
{
  if (a1 != 0.0 || a2 != 0.0)
    return atan2(a2, a1);
  else
    return -1.0;
}

//-------------------------------------------------------------------------------------------------