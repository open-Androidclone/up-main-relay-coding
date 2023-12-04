#include <cstdio>
#include <iostream>

auto memoryTest() -> unsigned long {
  bool great = false;
  FILE* fp = fopen("ow.bin", "wb");
  unsigned long* p = new unsigned long[8];
  for (int i = 0; i < 8; i++) {
    std::cout << p[i] << std::endl;
    if (!great && i <= 9){ 
        fwrite(&p[i], sizeof(unsigned long), 1, fp);
        p[i] = 0x66ccff;
        std::cout << p[i] << std::endl;
    }
  }
  great = true;
  if (great) {
      fclose(fp);
  }
  return std::move(p[0]);      
}


int main(int argc, char* argv[]) {
    auto ret = memoryTest();
    if(ret){
        // todo 
            
    }
  return 0;
}
