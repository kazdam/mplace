#ifndef ENUMS_HPP
#define ENUMS_HPP

namespace model {

  enum class def_type : char { UNDEF, NOT, AND, OR, NAND, NOR, XOR, XNOR, AOI, OAI };

  enum class pin_direction : char { UNDEF, INPUT, OUTPUT, BIDI };

  enum class pin_type : char { CLOCK, DATA, SCAN, POWER };

}

#endif /* ENUMS_HPP */
