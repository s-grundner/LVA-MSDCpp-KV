
#include "defines.h"

SC_MODULE(display) {
  sc_in<T> in;
  ServerSocket *sock;

  void work() {
    T num = in.read();
    // cout<<"display: @"<<sc_time_stamp()<<" out="<<num<<endl;

    try {
      if (sock)
        *sock << num.to_string() + '#';
    } catch (SocketException &e) {
      std::cout << "Exception was caught:" << e.description() << std::endl;
    }
  }

  SC_CTOR(display) {
    // process sentitive to positive clock edge
    SC_METHOD(work);
    sensitive << in;

    sock = 0;
  }
};
