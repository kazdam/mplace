#ifndef BOX_HPP
#define BOX_HPP

#include <vector>
#include "object.hpp"
#include "pin.hpp"

using std::vector;

namespace model {
  class box : public object {
    vector<pin> pins;
  public:
    box(const char* _name ) : object(_name) {}
    box(string& _name) : object(_name) {}
  };
}

#endif /* BOX_HPP */
