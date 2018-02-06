#ifndef OR_H_
#define OR_H_

#include "Gate.h"

class Or : public Gate
{
public:
  Or();

  bool process();

  int a;
  int b;

};

#endif /*OR*/
