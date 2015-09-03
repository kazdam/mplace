#ifndef CKTROW_HPP
#define CKTROW_HPP

#include <unordered_map>
#include "rectobj.hpp"
#include "box.hpp"

using std::string;
using std::unordered_map;
using std::make_pair;

namespace model {
  class cktrow : public rectobj {
    unordered_map<string, box*> boxes;
  public:
    cktrow () : rectobj("CKTROW", -1, -1, 0, 0) {}
    cktrow (const string& name,
	    int x, int y, int width, int height) : 
      rectobj(name, x, y, width, width) {}
    cktrow (const cktrow& rhs) : 
      rectobj(_name, 
	      rhs._x, rhs._y,
	      rhs._width, rhs._height) {}

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
  };
  ostream& operator<<(ostream& os, const cktrow& obj);
}


#endif /* CKTROW_HPP */
