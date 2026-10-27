#include <systemc.h>

// Generation of stimuli
SC_MODULE(stimGen) {
  int start;
  sc_in < bool > clock;
  sc_out < bool > reset;
  sc_out < bool > enabled;
  sc_out < bool > increment_mode;

  // idea: reset is true for #start cycles, afterwards false
  void calc();
  
  SC_HAS_PROCESS(stimGen);
  stimGen(sc_module_name);
};
