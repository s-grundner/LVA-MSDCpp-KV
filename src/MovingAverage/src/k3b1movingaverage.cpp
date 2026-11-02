#include "k3b1movingaverage.h"
void MovingAverage::regs() {
  if (reset.read()) {
    xn1.write(0);
    xn2.write(0);
    xn3.write(0);
    yn.write(0);
  } else if (clk.posedge()) {
    xn1.write(xn.read());
    xn2.write(xn1.read());
    xn3.write(xn2.read());
    yn.write(result.read());
  }
}
void MovingAverage::comb() {
  int i1, i2, i3;

  i1 = xn.read() + xn1.read();
  i2 = i1 + xn2.read();
  i3 = i2 + xn3.read();
  result.write(i3 / 4);
}
