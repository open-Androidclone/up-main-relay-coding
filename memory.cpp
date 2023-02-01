#include <ostream>
#include <iostream>
#include <memory>
#include <stdlib.h>
#include <stdio.h>
#ifndef MEMORY
#define MEMORY  0x0066ccff
#endif
using namespace std;
  
void memorytest(void){
  char* p = new char[8];
  /*
   * create a new memory as linux 
   * kernel virtual memory  
   * next up main is kde-yyds
   * androidroot9@outlook.com
  */ 
  char* hex = 0x0066ccff;
  while(1){
    /*w
   while loop for memory */
    p = &hex;
    FILE* file=fopen("ow.bin","wb");
  /*
  create a bin file
  */
  fprintf(file,"%#",&p);
    if(&p == &hex){
      /* if memory = 0x0066ccff   
      there break loop */
      fclose(file);
      delete[] p;
      break;
    }
  }
  cout <<"debug mod is enable "<<endl;
}

int main(void){
  memorytest();
  /*
  *call meqmorytest
  */
  return 0;
}