#ifndef BN_NUMBERS_H_
#define BN_NUMBERS_H_
#include <array>
#include <string>

namespace bn {

class Number {
public:
  explicit Number(const char * /* len must be 12 */);
  Number(Number &) = default;
  Number &operator=(Number &) = delete;
  ~Number() = default;

  bool operator==(const char *) const;
  bool operator!=(const char *) const;
  Number& operator++();
  
  bool isBeautiful() const;
  std::string toString() const;

private:
  unsigned leftSum() const;
  unsigned rightSum() const;
  unsigned sum(size_t begin, size_t end) const;

private:
  std::array<char, 13> data_;
};

} // namespace bn
#endif // BN_NUMBERS_H_
