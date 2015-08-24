#include "def.hpp"

using std::ostream;
using model::def;

ostream& model::operator<< (ostream& os, const def& obj)
{
  return os << "DEF " << obj.name() 
	    << " SIZE " << obj.height() << "x" << obj.width();
}

