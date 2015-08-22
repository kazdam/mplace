#include <iostream>
#include "box.hpp"

using std::cout;
using std::endl;

int main( int argc, char **argv )
{
  model::box foo("foo");

  cout << "Box is " << foo.get_name() << endl;
}
