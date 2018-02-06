#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <cassert>

#include "Gate.h"
#include "Not.h"
#include "Or.h"
#include "And.h"

/*
returns true if the circuit can be solved

when you create a new circuit put all of the gates into this function
to put it in a valid state after that, you can put just the updated
gates into this.
*/
bool solve(std::vector<Gate*> updates)
{
  for(Gate* u : updates)
  {
    std::stack<Gate*> next;
    std::map<Gate*, int> visited;
    std::map<Gate*, Gate*> ancestor;

    next.push(u);
    ancestor[u] = NULL;

    while(!next.empty())
    {
      Gate* g = next.top();
      next.pop();
      visited[g]++;

      if(g->process()) // the output value changed
      {
        if(visited[g] > 1)
        {
          //check if this is a cycle
          Gate* a = ancestor[g];
          while(a != NULL)
          {
            if(a == g) // this is a cycle
            {
              std::cout << "Circuit can not be solved\n";
              return false;

            }

            a = ancestor[a];

          }

        }

        // add newly updated nodes
        next.push(g->gate);
        ancestor[g->gate] = g;

      }

    }

  }

  std::cout << "Circuit solved\n";
  return true;

}

void testNotSelf()
{
  std::cout << "\ntesting not connected to itself\n";

  Not a;
  a.setOutput(&a, &a.input);

  assert(solve({&a}) == false);

}

void testNotNot()
{
  std::cout << "\ntesting two nots connected to one another\n";

  Not a;
  Not b;

  a.setOutput(&b, &b.input);
  b.setOutput(&a, &a.input);

  assert(solve({&a, &b}) == true);

}

void testOrNot()
{
  std::cout << "\ntesting or connected to a not connected back to the or\n";

  Or a;
  Not b;

  a.setOutput(&b, &b.input);
  b.setOutput(&a, &a.a);

  std::cout << "testing with the second value of the or = 0\n";
  a.b = 0;

  assert(solve({&a, &b}) == false);

  std::cout << "testing with the second value of the or = 1\n";
  a.b = 1;

  // only put the updated state into solve function (you can put both a and b but it doesn't matter).
  assert(solve({&a}) == true);

}

void testAndNot()
{
  std::cout << "\ntesting and connected to a not connected back to the and\n";

  And a;
  Not b;

  a.setOutput(&b, &b.input);
  b.setOutput(&a, &a.a);

  std::cout << "testing with the second value of the and = 0\n";
  a.b = 0;

  assert(solve({&a, &b}) == true);

  std::cout << "testing with the second value of the and = 1\n";
  a.b = 1;

  assert(solve({&a}) == false);

}

int main(int argc, char** argv)
{
  testNotSelf();
  testNotNot();
  testOrNot();
  testAndNot();

  return 0;

}
