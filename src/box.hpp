#ifndef BOX_HPP
#define BOX_HPP

#include <utility>
#include <unordered_map>
#include "object.hpp"
#include "enums.hpp"
#include "pin.hpp"

using std::string;
using std::unordered_map;
using std::make_pair;

namespace model {
  class box : public object {
    box* parent;
    enum box_type type;
    unordered_map<string, pin*> pins;
  public:
    box(const char* _name) : object(_name) {}
    box(const string& _name) : object(_name) {}
    
    void set_parent(box* _parent) {
      parent = _parent;
    }
    box* get_parent() const {
      return parent;
    }

    void add_pin(pin *_pin) {
      const string &name = _pin->get_name();
      auto it = pins.find(name);
      if (it == pins.end())
	pins.insert(make_pair(name, _pin));
    }
    void remove_pin(const string& name) {
      pins.erase(name);
    }
  };
}

#endif /* BOX_HPP */
