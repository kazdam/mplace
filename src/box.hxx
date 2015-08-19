#ifndef BOX_HXX
#define BOX_HXX

#include <vector>
#include "object.hxx"
#include "pin.hxx"

using std::vector;

namespace model {
  class box : public object {
    vector<pin> pins;
  public:
    box(const char* _name ) : object(_name) {}
    box(string& _name) : object(_name) {}
  };
}

#endif /* BOX_HXX */
