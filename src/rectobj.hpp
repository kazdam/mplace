#ifndef RECTOBJ_HPP
#define RECTOBJ_HPP

#include <ostream>
#include "object.hpp"
#include "enums.hpp"

using std::string;
using std::ostream;

namespace model {
  class rectobj : public object {
  protected:
    int _x;
    int _y;
    int _width;
    int _height;
  public:
    rectobj () : object("RECTOBJ"),
	       _x(-1), _y(-1), _width(0), _height(0) {}
    rectobj (const string& name,
	    int x, int y, int width, int height) : object(name),
	       _x(x), _y(y), _width(width), _height(width) {}
    rectobj (const rectobj& rhs) : object(_name),
			       _x(rhs._x), _y(rhs._y),
			       _width(rhs._width),
			       _height(rhs._height) {}

    
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
  ostream& operator<< (ostream& os, const rectobj& obj);
}

#endif /* RECTOBJ_HPP */
