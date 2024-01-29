#include "include/cpu.h"
#include <vector>

std::vector<byte> v = {

};

int main() {
  cpu c;
  c.load(v);
  c.run();
}
