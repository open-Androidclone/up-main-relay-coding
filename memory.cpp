#include <ostream>
#include <iostream>
#include <memory>
#include <stdio.h>
#ifndef MEMORY
#define MEMORY  0x0066ccff
#endif
using namespace std;
int memorytest(void){
  int *p = new int[8];
  /*
   * create a new memory as linux 
   * kernel virtual memory  
   * next up main is kde-yyds
   * androidroot9@outlook.com
  */ 
  while(1){
    /*while loop for memory */
    p  -> 0x0066ccff 
    if(&p ==MEMORY){
      /* if memory = 0x0066ccff 
      there break loop */
      break;
    }
  }
  cout<<"%d"<<&p<<endl;
  return p;
}
int main(void){
  memorytest();
  /*
  *call memorytest
  */
  return 0;
}
