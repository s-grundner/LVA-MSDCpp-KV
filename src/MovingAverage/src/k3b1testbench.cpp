#include "k3b1testbench.h"
#include <iostream>
using namespace std;
// Constructor
Testbench::Testbench(sc_module_name name) {
  SC_THREAD(generateStimuli);
  sensitive << clk.neg();
}
// Process
void Testbench::generateStimuli() {
  int i;

  reset.write(true);
  xn.write(0);
  wait();
  reset.write(false);
  xn.write(50);
  for (i = 0; i < 4; i++) {
    cout << "xn: " << 50 << ", yn: " << yn.read() << endl;
    wait();
  }
  xn.write(10);
  cout << "xn: " << 10 << ", yn: " << yn.read() << endl;
  wait();
  xn.write(50);
  for (i = 0; i < 5; i++) {
    cout << "xn: " << 50 << ", yn: " << yn.read() << endl;
    wait();
  }
}
