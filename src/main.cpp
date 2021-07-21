#include <iostream>
#include <stdexcept>
#include "numbers.h"

int main() {
  try {
    bn::Number n("123456789ABC");
    std::cout << n.toString() << std::endl;

    bn::Number n1("0000000000CC");
    std::cout << n1.toString() << std::endl;

    ++n1;
    std::cout << n1.toString() << std::endl;

    const char *str = "0000000000100";
    std::cout << (n1 == str) << std::endl;

  } catch(const std::runtime_error &e) {
    std::cout << e.what() << std::endl;
  }
}
