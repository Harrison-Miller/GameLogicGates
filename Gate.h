#ifndef GATE_H_
#define GATE_H_

class Gate
{
public:
  Gate();

  virtual ~Gate();

  virtual bool process();

  void setOutput(Gate* gate, int* output);

  Gate* gate;
  int* output;

};

#endif /*GATE*/
