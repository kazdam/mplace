#include "pin.hpp"

using std::ostream;
using model::pin;

ostream& model::operator<< (ostream& os, const pin& obj)
{
  return os << "PIN " << obj.name();
    //	    << " DIR " << obj.direction();
}

