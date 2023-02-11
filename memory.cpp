#include "memory.hpp"
unsigned long hexOfVirtualMeMory = 0x0066ccff;

void memorytest(void) {
  unsigned long *p = new unsigned long[8];
  
  /*
   * create a new memory as linux
   * kernel virtual memory
   * next up main is kde-yyds
   */
    for (int i = 0; i < 8; i++) {
      p[i] = hexOfVirtualMeMory;
      FILE  *file = fopen("ow.bin", "ab");
      fprintf(file, "%ld" "\r\n", p[i]);
      /*
   while loop for m
  create a bin file
  */
    cout << p[i] << endl;
      if (&p[i] == &hexOfVirtualMeMory) {
        delete[] p;
        fclose(file);
        break;
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
        cout << "memory test success" << endl;
        break;
      }
    }
      return 0;
    
  }