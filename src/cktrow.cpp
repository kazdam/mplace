#include "cktrow.hpp"

using std::ostream;
using model::cktrow;

ostream& model::operator<< (ostream& os, const cktrow& obj)
{
  return os << "CKTROW " << obj.name() 
	    << " X: " << obj.x() << " Y: " << obj.y()
	    << " W: " << obj.width() << " H: " << obj.height()
	    << " NUMBOXES: " << boxes.size();
}

