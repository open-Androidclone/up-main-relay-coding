#include <cstdio>
#include <iostream>

auto memoryTest() -> void {
  bool great = false;
  FILE* fp = fopen("ow.bin", "wb");
  unsigned long* p = new unsigned long[8];
  for (int i = 0; i < 8; i++) {
    std::cout << p[i] << std::endl;
    if (!great) {
      fwrite(&p[i], sizeof(unsigned long), 1, fp);
      p[i] = 0x66ccff;
      std::cout << p[i] << std::endl;
      great = true;
    }
  }
  if (great) {
    fclose(fp);
    delete[] p;
    p = nullptr;
  }
}

int main(int argc, char* argv[]) {
  memoryTest();
  return 0;
}
