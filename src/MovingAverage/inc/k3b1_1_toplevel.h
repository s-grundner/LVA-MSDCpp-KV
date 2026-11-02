#ifndef K3B1_1_TOPLEVEL_H
#define K3B1_1_TOPLEVEL_H
#include <systemc>
using namespace sc_core;
#include "k3b1movingaverage.h"
#include "k3b1testbench.h"

struct Toplevel : public sc_module {
  // Modules
  Testbench tb;
  MovingAverage ma;
  // Constructor
  Toplevel(sc_module_name name);

private:
  sc_clock clock;
  sc_signal<int> xSignal, ySignal;
  sc_signal<bool> resetSignal;
};
#endif
