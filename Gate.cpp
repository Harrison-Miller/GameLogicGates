#include "Gate.h"

Gate::Gate()
{
}

Gate::~Gate()
{

}

bool Gate::process()
{
}

void Gate::setOutput(Gate* g, int* o)
{
  gate = g;
  output = o;

}
