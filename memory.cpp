#include "memory.hpp"
void memorytest(void) {
  int *p = new int[8];
  /*
   * create a new memory as linux
   * kernel virtual memory
   * next up main is kde-yyds
   */
  while (1) {
    for (int i = 0; i < 8; i++) {
      p[i] = hex;
      FILE  *file = fopen("ow.bin", "wb");
      fprintf(file, "%d", p[i]);
      /*
   while loop for m
  create a bin file
  */
      if (p[i] == hex) {
        cout << p[i] << endl;
        delete[] p;
        cout << "memory test success" << endl;
        fclose(file);
        break;
      }
    }
  }
    cout << "debug mod is enable " << endl;
  }
int main(void) {
    int i = 0;
    while (1) {
      memorytest();
      i++;
      sleep(1);
      if (i == 20) {
        break;
      }
    }
    return 0;
    
  }