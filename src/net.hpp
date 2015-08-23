#ifndef NET_HPP
#define NET_HPP

#include <unordered_map>
#include "object.hpp"
#include "pin.hpp"

using std::string;
using std::unordered_map;
using std::make_pair;
using model::pin;

namespace model {
  class net : public object {
    unordered_map<string, pin*> pins;
  public:
    net(const char* _name ) : object(_name) {}
    net(const string& _name) : object(_name) {}

    void connect(pin* _pin) {
      const string& name = _pin->get_name();
      if (pins.find(name) == pins.end())
	pins.insert(make_pair(name, _pin));
    }
  };
}

#endif /* NET_HPP */
