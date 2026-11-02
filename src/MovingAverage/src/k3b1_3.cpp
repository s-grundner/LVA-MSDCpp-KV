#include "k3b1_3_toplevel.h"
#include "k3b1testbench.h" //Necessary for traces

int sc_main(int argc, char *argv[]) {
  Toplevel *top;
  top = new Toplevel("top");

  // Create trace file
  sc_trace_file *fp;
  fp = sc_create_vcd_trace_file("traces");
  sc_trace(fp, top->tb->clk, "clk");
  sc_trace(fp, top->tb->reset, "reset");
  sc_trace(fp, top->tb->yn, "y");
  sc_trace(fp, top->tb->xn, "x");

  // Start simulation
  sc_start(100, SC_NS);

  // Close trace file
  sc_close_vcd_trace_file(fp);

  return 0;
}
