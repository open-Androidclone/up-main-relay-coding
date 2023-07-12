#include "memory.hpp"
#include <iostream>
#include <ostream>
using namespace std;

auto mauemorytest(void) -> void {
  unsigned long *p = new unsigned long[8];
  for (int i; i<8; i++) {
    cout << p[i] << endl;

  }

 /*
   * create a new memory as linux 
   * kernel virtual memory
   * next up main is kde-yyds
   */

}
int main (int argc, char *argv[]) {
  mauemorytest();
  return 0;
}
