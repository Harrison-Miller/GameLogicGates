#include "Not.h"

Not::Not() : input(0)
{
}

bool Not::process()
{
  if(*output != !input)
  {
    *output = !input;
    return true;

  }

  return false;

}
