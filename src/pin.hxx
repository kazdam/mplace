#ifndef PIN_HXX
#define PIN_HXX

#include <vector>
#include "object.hxx"

using std::vector;

namespace model {
  class pin : public object {
    
  public:
    pin( string& _name ) : object( _name ) {}
  };
}

#endif /* PIN_HXX */
