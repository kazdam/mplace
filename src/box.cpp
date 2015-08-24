#include "box.hpp"

using std::ostream;
using model::box;

ostream& model::operator<< (ostream& os, const box& obj)
{
  return os << "BOX " << obj.name() 
	    << " SIZE " << obj.height() << "x" << obj.width();
}

