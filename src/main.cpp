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
    std::cout << "Beautiful: " << n1.isBeautiful() << std::endl;

    bn::Number n2("1234C601234C");
    std::cout << n2.toString() << std::endl;
    std::cout << "Beautiful: " << n2.isBeautiful() << std::endl;

  } catch(const std::runtime_error &e) {
    std::cout << e.what() << std::endl;
  }
}
