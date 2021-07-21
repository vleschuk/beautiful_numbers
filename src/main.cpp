#include <iostream>
#include <stdexcept>
#include "numbers.h"

int main() {
  try {
    bn::Number n("123456789ABC");
  } catch(const std::runtime_error &e) {
    std::cout << e.what();
  }
}
