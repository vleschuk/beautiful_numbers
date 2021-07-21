#include <cctype>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include "numbers.h"

namespace bn {

  Number::Number(const char *str) {
    auto sz = strlen(str);
    if(sz != 12) {
      throw std::runtime_error("String len must be 12");
    }
    data_[0] = '0';
    for(size_t i = 1; i < 13; ++i) {
      char c = static_cast<char>(std::toupper(static_cast<int>(str[i-1])));
      if(c > '9' && (c < 'A' || c > 'C')) {
        std::stringstream ss;
        ss << "Char value out of range: " << c;
        throw std::runtime_error(ss.str().c_str());
      }
      data_[i] = c;
    }
  }
} // namespace bn
