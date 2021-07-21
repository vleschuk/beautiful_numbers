#include <cctype>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <unordered_map>
#include "numbers.h"

namespace {

std::unordered_map<char, unsigned> decimalValues{
  {'0',0},
  {'1',1},
  {'2',2},
  {'3',3},
  {'4',4},
  {'5',5},
  {'6',6},
  {'7',7},
  {'8',8},
  {'9',9},
  {'A',10},
  {'B',11},
  {'C',12}};

} // anon ns

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
      else if(*it == 'A') {
        *it = 'B';
        break;
      }
      else if(*it == 'B') {
        *it = 'C';
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

  unsigned Number::sum(size_t begin, size_t end) const {
    if(begin > (data_.size() - 1) || end > (data_.size() - 1) || begin > end) {
      throw std::runtime_error("Invalid boundaries");
    }
    unsigned res = 0;
    for(size_t i = begin; i <= end; ++i) {
      res += decimalValues[data_[i]];
    }
    return res;
  }

  unsigned Number::leftSum() const {
    return sum(0, 5);
  }

  unsigned Number::rightSum() const {
    return sum(7, 12);
  }

  bool Number::isBeautiful() const {
    return leftSum() == rightSum();
  }

} // namespace bn
