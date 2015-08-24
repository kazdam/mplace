#ifndef DEF_HPP
#define DEF_HPP

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
  class def : public object {
    int _x;
    int _y;
    int _width;
    int _height;
    enum def_type _type;
    unordered_map<string, pin*> pins;
  public:
    def (const string &name) : object(name), 
			       _x(-1), _y(-1), _width(0), _height(0),
			       _type(def_type::UNDEF) {}
    def (const def& rhs) : _width(rhs._width),
			   _height(rhs._height),
			   _type(rhs._type),
			   pins(rhs.pins),
			   object(rhs) {}
    
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
  };
  ostream& operator<<(ostream& os, const def& obj);
}


#endif /* DEF_HPP */
