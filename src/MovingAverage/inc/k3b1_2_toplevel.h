#ifndef K3B1_2_TOPLEVEL_H
#define K3B1_2_TOPLEVEL_H
#include <systemc>
using namespace sc_core;

struct Testbench;
struct MovingAverage;

struct Toplevel : public sc_module {
  // Module Pointers
  Testbench *tb;
  MovingAverage *ma;
  // Constructor
  Toplevel(sc_module_name name);

private:
  sc_clock clock;
  sc_signal<int> xSignal, ySignal;
  sc_signal<bool> resetSignal;
};
#endif
