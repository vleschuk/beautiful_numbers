#include <iostream>
#include <stdexcept>
#include "numbers.h"

int main() {
  unsigned long count = 1; // all zeros
  try {
    bn::Number n("000000000000");
    do {
      ++n;
      if(n.isBeautiful()) {
        ++count;
      }
    } while(n != "0CCCCCCCCCCCC");
    std::cout << "Count: " << count << std::endl;
  } catch(const std::runtime_error &e) {
    std::cout << e.what() << std::endl;
  }
}
