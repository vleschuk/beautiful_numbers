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

  std::string Number::toString() const {
    std::stringstream ss;
    for(auto c : data_) {
      ss << c;
    }
    return ss.str();
  }

  Number& Number::operator++() {
    for(auto it = data_.rbegin(); it != data_.rend() - 1; ++it) {
      if(*it == 'C') {
        if(it == (data_.rend() - 2)) {
          throw std::runtime_error("Value too large");
        }
        *it = '0';
        continue;
      }
      if(*it == '9') {
        *it = 'A';
        break;
      }

      ++(*it);
      break;
    }
    return *this;
  }

  bool Number::operator==(const char *str) const {
    if(!str) {
      return false;
    }

    size_t len = strlen(str);
    if(len != data_.size()) {
      return false;
    }

    for(size_t i = 0; i < data_.size(); ++i) {
      char c = static_cast<char>(std::toupper(static_cast<int>(str[i])));
      if(data_[i] != c) {
        return false;
      }
    }

    return true;
  }

} // namespace bn
