#ifndef NOT_H_
#define NOT_H_

#include "Gate.h"

class Not : public Gate
{
public:
  Not();

  bool process();

  int input;

};

#endif /*NOT*/
