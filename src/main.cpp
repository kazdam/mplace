#include <iostream>
#include "model.hpp"

using std::cout;
using std::endl;

int main (int argc, char **argv)
{
  //model::box foo("foo");
  //cout << "Box is " << foo.get_name() << endl;
  
  for (int i = 1; i < argc; ++i) {
    model::build(string(argv[i]));
  }

  model::print();
}
