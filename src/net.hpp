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
    net (const char* name ) : object(name) {}
    net (const string& name) : object(name) {}
    net (const net& rhs) : pins(rhs.pins), object(rhs) {}

    void connect (pin* p) {
      const string& name = p->name();
      if (pins.find(name) == pins.end())
	pins.insert(make_pair(name, p));
    }
  };
}

#endif /* NET_HPP */
