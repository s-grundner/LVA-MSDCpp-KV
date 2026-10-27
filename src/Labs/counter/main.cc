
#include <systemc.h>

#include <unistd.h>
#include <fstream>
#include <iostream>

#include <ServerSocket.h>
#include <SocketException.h>

#include "defines.h"
#include "counter.h"
#include "stimGen.h"
#include "display.h"



ServerSocket* server;
ServerSocket sock;

int sc_main(int argc, char *argv[]) {

  int port = 30000;
  server = new ServerSocket(port);
  cout<< "-I- using port " << port << " for I/O \n";
  cout<< "-I- waiting for connection ..."<<flush<<endl;
  server->accept(sock);
  cout<< "-I- connection established"<<flush<<endl;


  sc_clock clk("CLOCK", 10, SC_NS); // period of 10 ns

  sc_signal < bool > reset;
  sc_signal < bool > enabled;
  sc_signal < bool > increment_mode;
  sc_signal < T > out;

  stimGen sg("Stimuli");
  sg.start = 5; // how long is reset true
  // port binding
  sg.reset(reset); 
  sg.enabled(enabled);
  sg.increment_mode(increment_mode);
  sg.clock(clk);

  // instantiate counter
  counter co("Counter");
  // port binding
  co.clock(clk);
  co.reset(reset);
  co.enabled(enabled);
  co.increment_mode(increment_mode);
  co.out(out);
  
  // instantiate display
  display dis("Display");
  dis.in(out);
  dis.sock = &sock;


  // Tracing
  sc_trace_file *trf = sc_create_vcd_trace_file("counter");
  sc_trace(trf, reset, "reset");
  sc_trace(trf, out, "out");

  // Go
  int cycles = 62; // set number of cycles to simulate
  sc_time st(cycles*10+10, SC_NS);
  cout<<"-I- Start of simulation"<<endl;
  sc_start(st);
  
  sc_close_vcd_trace_file(trf);

  return 0;
}
