#include <cstdlib>
#include <iostream>

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
  Data* data = new Data();
  data->x    = 5;
  data->y    = 89;

  std::cout << "address of data:          " << data << " (" << data->x << "," << data->y << ")" << std::endl;

  uintptr_t ptr = serialize(data);
  std::cout << "result of serialized ptr: 0x" << std::hex << ptr << std::endl;

  Data* data2;
  data2 = deserialize(ptr);

  std::cout << "address of data2:         " << data2 << " (" << data2->x << "," << data2->y << ")" << std::endl;

  delete data;

  return EXIT_SUCCESS;
}
