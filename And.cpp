#include "And.h"

And::And() : a(0), b(0)
{
}

bool And::process()
{
  if(*output != a & b)
  {
    *output = a & b;
    return true;

  }

  return false;

}
