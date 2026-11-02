#include "k3b1movaverage_cthread.h"
// Constructor
MovingAverage::MovingAverage(sc_module_name name) {
  SC_CTHREAD(movAverageProcess, clk.pos());
  reset_signal_is(reset, true);
}
void MovingAverage::movAverageProcess() {
  int xn1, xn2, xn3, result;
  // Reset section
  xn1 = 0;
  xn2 = 0;
  xn3 = 0;
  yn.write(0);
  // Main loop
  while (true) {
    wait();
    result = (xn.read() + xn1 + xn2 + xn3) / 4;
    yn.write(result);
    xn3 = xn2;
    xn2 = xn1;
    xn1 = xn.read();
  }
}
