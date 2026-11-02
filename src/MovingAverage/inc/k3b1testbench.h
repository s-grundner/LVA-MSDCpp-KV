#ifndef K3B1TESTBENCH_H
#define K3B1TESTBENCH_H
#include <systemc>
using namespace sc_core;

struct Testbench : public sc_module {
  // Ports
  sc_in<bool> clk;
  sc_in<int> yn;
  sc_out<bool> reset;
  sc_out<int> xn;
  // Processes
  void generateStimuli();
  // Constructor
  SC_HAS_PROCESS(Testbench);
  Testbench(sc_module_name);
};
#endif
