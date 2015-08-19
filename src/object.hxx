#ifndef OBJECT_HXX
#define OBJECT_HXX

#include <string>

using std::string;

namespace model {
  class object {
    string name;
  public:
    object(const char* _name) : 
      name(_name) {}
    object(string& _name) :
      name(_name) {}

    const char* get_name() {
      return name.data();
    }
    void set_name(string& _name) {
      name = _name;
    }
  };
}

#endif /* BOX_HXX */
