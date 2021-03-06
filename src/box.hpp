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
  class def;
  class box : public object {
    def* _parent;
    int _x;
    int _y;
    int _width;
    int _height;
    unordered_map<string, pin*> pins;
  public:
    box (const string &name) : object(name), _parent(nullptr),
			       _x(-1), _y(-1), _width(0), _height(0)
			       {}
    box (const box& rhs) : _parent(rhs._parent),
			   _width(rhs._width),
			   _height(rhs._height),
			   pins(rhs.pins),
			   object(rhs) {}
    
    def* set_parent (def* parent) {
      return _parent = parent;
    }
    def* parent() const {
      return _parent;
    }
    
    int set_x ( int x ) {
      return _x = x;
    }
    int x () const {
      return _x;
    }
    int set_y ( int y ) {
      return _y = y;
    }
    int y () const {
      return _y;
    }
    int set_height ( int height ) {
      return _height = height;
    }
    int height () const {
      return _height;
    }
    int set_width ( int width ) {
      return _width = width;
    }
    int width () const {
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
  };
  ostream& operator<<(ostream& os, const box& obj);
}


#endif /* BOX_HPP */
