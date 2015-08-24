#ifndef BOX_HPP
#define BOX_HPP

#include <ostream>
#include <utility>
#include <unordered_map>
#include "object.hpp"
#include "enums.hpp"
#include "pin.hpp"

using std::string;
using std::unordered_map;
using std::make_pair;
using std::ostream;
using std::endl;

namespace model {
  class box : public object {
    box* _parent;
    uint32_t _width;
    uint32_t _height;
    enum box_type _type;
    unordered_map<string, pin*> pins;
  public:
    box (const char* name) : object(name), _parent(nullptr) {}
    box (const string& name) : object(name), _parent(nullptr) {}
    box (const box& rhs) : _parent(rhs._parent),
			   _width(rhs._width),
			   _height(rhs._height),
			   _type(rhs._type),
			   pins(rhs.pins),
			   object(rhs) {}
    
    box* set_parent (box* parent) {
      return _parent = parent;
    }
    box* parent() const {
      return _parent;
    }
    
    uint32_t set_height ( uint32_t height ) {
      return _height = height;
    }
    uint32_t height () const {
      return _height;
    }
    uint32_t set_width ( uint32_t width ) {
      return _width = width;
    }
    uint32_t width () const {
      return _width;
    }
    
    void add_pin (pin *p) {
      const string &name = p->name();
      auto it = pins.find(name);
      if (it == pins.end())
	pins.insert(make_pair(name, p));
    }
    void remove_pin (const string& name) {
      pins.erase(name);
    }

    // ostream& print_on(ostream& os) const;
    // ostream& operator<<(ostream& os) const;
  };
  ostream& operator<<(ostream& os, const box& obj);
}


#endif /* BOX_HPP */
