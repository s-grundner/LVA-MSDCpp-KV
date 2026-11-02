#ifndef K3B1MOVINGAVERAGE_H
#define K3B1MOVINGAVERAGE_H
#include <systemc>
using namespace sc_core;

SC_MODULE(MovingAverage) {
  // Ports
  sc_in<bool> clk, reset;
  sc_in<int> xn;
  sc_out<int> yn;
  // Processes
  void regs();
  void comb();
  // Constructor
  SC_CTOR(MovingAverage) {
    SC_METHOD(regs);
    sensitive << clk << reset;
    SC_METHOD(comb);
    sensitive << xn << xn1 << xn2 << xn3;
  };

private:
  // Internal signals
  sc_signal<int> xn1, xn2, xn3, result;
};
#endif
