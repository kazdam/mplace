#include <unordered_map>
#include <vector>
#include <fstream>
#include <boost/tokenizer.hpp>
#include "model.hpp"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::to_string;
using std::unordered_map;
using std::vector;
using std::make_pair;
using model::box;
using model::net;
using model::pin;

unordered_map<string, box*> boxes;
unordered_map<string, net*> nets;
unordered_map<string, pin*> pins;

typedef boost::char_separator<char> separator_type;
typedef boost::tokenizer<separator_type> tokenizer_type;

int net_count = 0;
static void gen_net_name (string& name) 
{
  name = "NET" + to_string(net_count++);
}

void model::build (const string& file_name)
{
  cout << "file: " << file_name << endl;
  //ifstream input(file_name, std::ifstream::in);
  ifstream input(file_name);
  while (input.good()) {
    string buffer;
    getline(input, buffer);
    separator_type sep("(), ");
    tokenizer_type tokens(buffer, sep);
    vector<string> pin_names;
    // each non-blank line parsed is a net
    for (auto &it : tokens) {
      if (it.compare("#") == 0)
	break;			// skip parsing of comments
      pin_names.push_back(it);
    }
    if (pin_names.size() > 0) {
      string name;
      gen_net_name(name);
      net *n = new net(name);
      nets.insert(make_pair(name, n));
      for (string name : pin_names) {
	// tokenize the pin name, if it is just a single token w/o a
	// ., then it's a pin to be added to the global pin scope.  if
	// it has a ., then a usage may need to be created
	size_t pos = name.find('.');
	if (pos != string::npos) {
	  // this is a usage pin
	  const string &box_name = name.substr(0, pos);
	  const string &pin_name = name.substr(pos+1, name.length());
	  auto it = boxes.find(box_name);
	  if (it != boxes.end()) {
	    box* b = it->second;
	    pin *p = new pin(pin_name);
	    b->add_pin(p);
	    n->connect(p);
	  } else {
	    cout << "create new box: " << box_name << endl;
	    box* b = new box(box_name);
	    boxes.insert(make_pair(box_name, b));
	    pin *p = new pin(pin_name);
	    b->add_pin(p);
	    n->connect(p);
	  }
	} else {
	  // this is a proto pin
	  auto it = pins.find(name);
	  if (it != pins.end()) {
	    pin *p = it->second;
	    n->connect(p); 
	  } else {
	    pin* p = new pin(name);
	    pins.insert(make_pair(name, p));
	    n->connect(p);
	  }
	}
      }
    }
  }
}

void model::print () {
  for (auto &p : boxes) {
    std::cout << *(p.second) << std::endl;
  }
  for (auto &p : pins) {
    std::cout << "PIN " << p.first << std::endl;
  }
  for (auto &p : nets) {
    std::cout << "NET " << p.first << std::endl;
  }
}

	 
