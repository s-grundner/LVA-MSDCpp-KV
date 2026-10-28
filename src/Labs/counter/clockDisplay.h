
#include "defines.h"
#include <iomanip>
#include <iostream>

SC_MODULE(clockDisplay) {
  sc_in<T> ss;
  sc_in<T> mm;
  sc_in<T> hh;
  ServerSocket *sock;

  void work() {
    T ss_val = ss.read();
    T mm_val = mm.read();
    T hh_val = hh.read();

    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << hh_val.to_string()
        << std::setw(2) << mm_val.to_string() << std::setw(2)
        << ss_val.to_string() << '#';

    try {
      if (sock)
        *sock << oss.str();
    } catch (SocketException &e) {
      std::cout << "Exception was caught:" << e.description() << std::endl;
    }
  }

  SC_CTOR(clockDisplay) {
    // process sentitive to positive clock edge
    SC_METHOD(work);
    sensitive << ss << mm << hh;

    sock = 0;
  }
};
