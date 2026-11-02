#ifndef K3B1MOVAVERAGE_CPPSTYLE_H
#define K3B1MOVAVERAGE_CPPSTYLE_H
#include <systemc>
using namespace sc_core;

struct MovingAverage : public sc_module {
  // Ports
  sc_in<bool> clk, reset;
  sc_in<int> xn;
  sc_out<int> yn;
  // Processes
  void regs();
  void comb();
  // Constructor
  SC_HAS_PROCESS(MovingAverage);
  MovingAverage(sc_module_name);

private:
  // Internal signals
  sc_signal<int> xn1, xn2, xn3, result;
};
#endif
