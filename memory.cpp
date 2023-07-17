#include <iostream>
#include <ostream>
using namespace std;

auto mauemorytest(void) -> void {
  bool great = false;
  unsigned long* p = new unsigned long[8];
  for (int i; i < 8; i++) {
    cout << p[i] << endl;
    if (great == false) {
      p[i] = 0x66ccff;
      cout << p[i] <<endl;
      great = true;
    }
      if (great)  {
      delete [] p; 
    }
  }

  /*
   * create a new memory as linux
   * kernel virtual memory
   * next up main is kde-yyds
   */
}
//kde-yyds 
int main(int argc, char *argv[]) {
  mauemorytest();
  return 0;
}
