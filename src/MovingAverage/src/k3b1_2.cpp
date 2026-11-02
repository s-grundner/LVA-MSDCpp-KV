#include "k3b1_2_toplevel.h"

int sc_main(int argc, char *argv[]) {
  Toplevel top("top");
  // Start simulation
  sc_start(100, SC_NS);

  return 0;
}
