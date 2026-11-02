#include "k3b1_1_toplevel.h"
// Constructor
Toplevel::Toplevel(sc_module_name name)
    : tb("tb"), ma("ma"), clock("clock", 10, SC_NS) {
  // Connect instances
  tb.clk(clock);
  tb.xn(xSignal);
  tb.yn(ySignal);
  tb.reset(resetSignal);
  ma.clk(clock);
  ma.xn(xSignal);
  ma.yn(ySignal);
  ma.reset(resetSignal);
}
