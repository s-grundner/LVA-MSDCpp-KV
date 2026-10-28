#ifndef K3B4ALU_H
#define K3B4ALU_H
#include <systemc>
using namespace sc_core; // SC core language
using namespace sc_dt;   // SC data types

struct Alu : public sc_module {
  // Ports
  sc_in<bool> clk;
  sc_in<sc_lv<2>> mode;
  sc_in<sc_uint<4>> distance;
  sc_in<sc_int<8>> opA, opB;
  sc_out<sc_int<8>> result;

  // Processes
  void aluProcess();

  // Constructor
  SC_HAS_PROCESS(Alu);
  Alu(sc_module_name);
};
#endif
