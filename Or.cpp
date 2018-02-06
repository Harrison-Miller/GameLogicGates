#include "Or.h"

Or::Or() : a(0), b(0)
{
}

bool Or::process()
{
  if(*output != a | b)
  {
    *output = a | b;
    return true;

  }

  return false;

}
