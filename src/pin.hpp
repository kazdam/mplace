#ifndef PIN_HPP
#define PIN_HPP

#include <ostream>
#include "object.hpp"
#include "enums.hpp"

using std::ostream;

namespace model {
  class net;

  class pin : public object {
    enum pin_direction _direction;
    net* _net;
  public:
    pin (const string &name ) : object(name), _direction(pin_direction::UNDEF) {}
    pin (const pin &pin) : object(pin), _net(pin._net)  {}

    enum pin_direction set_direction ( enum pin_direction d ) {
      return _direction = d;
    }
    enum pin_direction direction () const {
      return _direction;
    }
    
  };

  ostream& operator<<(ostream& os, const pin& obj);

}

#endif /* PIN_HPP */
