#ifndef PROTO_HPP
#define PROTO_HPP

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
  class proto : public object {
    int _x;
    int _y;
    int _width;
    int _height;
    unordered_map<string, pin*> pins;
    unordered_map<string, net*> nets;
    unordered_map<string, box*> boxes;
  public:
    proto () : object("TOP"),
	       _x(-1), _y(-1), _width(0), _height(0) {}
    proto (const proto& rhs) : object(_name),
			       _x(rhs._x), _y(rhs._y),
			       _width(rhs._width),
			       _height(rhs._height),
			       pins(rhs.pins),
			       nets(rhs.nets),
			       boxes(rhs.boxes) {}

    void read (const string& file_name);
    void print () const;
    
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
    pin *locate_pin (const string &name) {
      auto it = pins.find(name);
      if (it != pins.end()) {
	return it->second;
      } else {
	return nullptr;
      }
    }

    void add_box (box *b) {
      const string &name = b->name();
      auto it = boxes.find(name);
      if (it == boxes.end())
	boxes.insert(make_pair(name, b));
    }
    void remove_box (const string& name) {
      boxes.erase(name);
    }
    box *locate_box (const string &name) {
      auto it = boxes.find(name);
      if (it != boxes.end()) {
	return it->second;
      } else {
	return nullptr;
      }
    }

    void add_net (net *b) {
      const string &name = b->name();
      auto it = nets.find(name);
      if (it == nets.end())
	nets.insert(make_pair(name, b));
    }
    void remove_net (const string& name) {
      nets.erase(name);
    }
    net *locate_net (const string &name) {
      auto it = nets.find(name);
      if (it != nets.end()) {
	return it->second;
      } else {
	return nullptr;
      }
    }

  };
  ostream& operator<<(ostream& os, const proto& obj);
}


#endif /* PROTO_HPP */
