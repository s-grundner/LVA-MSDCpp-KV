#include "k3b1movaverage_cppstyle.h"
#include "k3b1testbench.h"

int sc_main(int argc, char *argv[]) {
  Testbench *tb;
  tb = new Testbench("tb");
  MovingAverage *ma;
  ma = new MovingAverage("ma");

  sc_clock clock("clock", 10, SC_NS);
  sc_signal<int> xSignal, ySignal;
  sc_signal<bool> resetSignal;

  tb->clk(clock);
  tb->xn(xSignal);
  tb->yn(ySignal);
  tb->reset(resetSignal);
  ma->clk(clock);
  ma->xn(xSignal);
  ma->yn(ySignal);
  ma->reset(resetSignal);

  // Start simulation
  sc_start(100, SC_NS);

  return 0;
}
