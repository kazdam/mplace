#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <string>

using std::string;

namespace model {
  class object {
  protected:
    string name;
  public:
    object(const char* _name) : 
      name(_name) {}
    object(const string& _name) :
      name(_name) {}
    const string& get_name() const {
      return name;
    }
    const char* get_cname() const {
      return name.data();
    }
    void set_name(const string& _name) {
      name = _name;
    }
  };
}

#endif /* OBJECT_HPP */
