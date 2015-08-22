#ifndef PIN_HPP
#define PIN_HPP

#include <vector>
#include "object.hpp"

using std::vector;

namespace model {
  class pin : public object {
    
  public:
    pin( string& _name ) : object( _name ) {}
  };
}

#endif /* PIN_HPP */
