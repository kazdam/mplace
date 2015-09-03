#include "rectobj.hpp"

using std::ostream;
using model::rectobj;

ostream& model::operator<< (ostream& os, const rectobj& obj)
{
  return os << "RECTOBJ " << obj.name() 
	    << " X: " << obj.x() << " Y: " << obj.y()
	    << " W: " << obj.width() << " H: " << obj.height();
}

