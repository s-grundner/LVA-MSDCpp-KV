#include "k3b1_3_toplevel.h"
#include "k3b1movingaverage.h"
#include "k3b1testbench.h"

// Constructor
Toplevel::Toplevel(sc_module_name name)
    : sc_module(name), clock("clock", 10, SC_NS) {
  // Create instances
  tb = new Testbench("tb");
  ma = new MovingAverage("ma");
  // Connect instances
  (*tb)(clock, ySignal, resetSignal, xSignal);
  (*ma)(clock, resetSignal, xSignal, ySignal);
}
