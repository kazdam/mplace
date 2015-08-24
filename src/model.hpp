#ifndef MODEL_HPP
#define MODEL_HPP

#include <string>
#include "box.hpp"
#include "net.hpp"
#include "pin.hpp"

using std::string;

namespace model {
  ostream& operator<<(ostream& os, const box& obj);

  void build (const string& filename);
  void print ();
}

#endif /* MODEL_HPP */
