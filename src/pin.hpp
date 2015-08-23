#ifndef PIN_HPP
#define PIN_HPP

#include "object.hpp"

namespace model {
  class net;

  class pin : public object {
    net* _net;
  public:
    pin (const string &_name ) : object(_name) {}
    pin (const pin &pin) : object(name) {
      _net = pin._net;
    }
  };
}

#endif /* PIN_HPP */
