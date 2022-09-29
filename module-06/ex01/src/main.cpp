#include <cassert>
#include <cstdlib>
#include <iostream>

typedef unsigned long uintptr_t;

struct Data {
  int x;
  int y;
};

uintptr_t serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}

// static_cast can only cast between two related types
// reinterpret_cast tells the compiler to reinterpret parts of the bits

int main(void) {
  Data data = {42, 21};
  std::cout << "address of data:          " << &data << " (" << data.x << "," << data.y << ")" << std::endl;

  uintptr_t raw_address = serialize(&data);
  std::cout << "result of serialized ptr: " << std::showbase << std::hex << raw_address << std::endl;

  Data* data2 = deserialize(raw_address);
  assert(data2 == &data);  // check that the deserialized pointer is the same as the original
  std::cout << "address of data2:         " << std::dec << data2 << " (" << data2->x << "," << data2->y << ")"
            << std::endl;

  return EXIT_SUCCESS;
}
