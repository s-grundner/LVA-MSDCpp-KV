
// modulo counter
#include "defines.h"
#include <algorithm>
#include <stdexcept>

SC_MODULE(counter) {
  sc_in_clk clock;
  sc_in<bool> reset;
  sc_in<bool> enabled;
  sc_in<bool> increment_mode;
  sc_in<bool> strobe;
  sc_in<T> init;
  sc_in<T> overflow;
  sc_out<bool> overflow_strobe;
  sc_out<T> out;

  // counter value
  T count_val;
  bool overflow_strobe_val;

  void do_count() {
    overflow_strobe_val = false;
    if (reset.read()) {
      count_val = init.read();
    } else {
      if (count_val >= overflow.read()) {
        count_val = 0;
        overflow_strobe_val = true;
      } else if (enabled.read() && strobe.read()) {
        if (increment_mode.read()) {
          count_val++;
        } else {
          count_val--;
        }
      }
    }
    out = count_val;
    overflow_strobe = overflow_strobe_val;
  }

  SC_CTOR(counter) {
    // process sentitive to positive clock edge
    SC_METHOD(do_count);
    sensitive << clock.pos();
  }
};
