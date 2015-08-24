#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <string>

using std::string;

namespace model {
  class object {
  protected:
    string _name;
  public:
    object(const char* name) : 
      _name(name) {}
    object(const string& name) :
      _name(name) {}
    object (const object &p) {
      _name = p._name;
    }


    const string& name() const {
      return _name;
    }
    const char* cname() const {
      return _name.data();
    }
    const string& set_name(const string& name) {
      return _name = name;
    }
  };
}

#endif /* OBJECT_HPP */
