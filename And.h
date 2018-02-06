#ifndef AND_H_
#define AND_H_

#include "Gate.h"

class And : public Gate
{
public:
  And();

  bool process();

  int a;
  int b;

};

#endif /*AND*/
