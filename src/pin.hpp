#ifndef PIN_HPP
#define PIN_HPP

#include "object.hpp"

namespace model {
  class net;

  class pin : public object {
    net* _net;
  public:
    pin (const string &name ) : object(name) {}
    pin (const pin &pin) : _net(pin._net), object(pin) {}
  };
}

#endif /* PIN_HPP */
