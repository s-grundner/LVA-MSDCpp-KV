#ifndef K3B1MOVAVERAGE_CTHREAD_H
#define K3B1MOVAVERAGE_CTHREAD_H
#include <systemc>
using namespace sc_core;

struct MovingAverage : public sc_module {
  // Ports
  sc_in<bool> clk, reset;
  sc_in<int> xn;
  sc_out<int> yn;
  // Processes
  void movAverageProcess();
  // Constructor
  SC_HAS_PROCESS(MovingAverage);
  MovingAverage(sc_module_name);
};
#endif
