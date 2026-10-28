
#include <ctime>
#include <systemc.h>

#include <fstream>
#include <iostream>
#include <unistd.h>

#include <ServerSocket.h>
#include <SocketException.h>

#include "clockDisplay.h"
#include "counter.h"
#include "defines.h"
#include "stimGen.h"

ServerSocket *server;
ServerSocket sock;

int sc_main(int argc, char *argv[]) {

  int port = 30000;
  server = new ServerSocket(port);
  cout << "-I- using port " << port << " for I/O \n";
  cout << "-I- waiting for connection ..." << flush << endl;
  server->accept(sock);
  cout << "-I- connection established" << flush << endl;

  sc_clock clk("CLOCK", 10, SC_NS); // period of 10 ns

  sc_signal<bool> reset;
  sc_signal<bool> enabled;
  sc_signal<bool> increment_mode;
  sc_signal<bool> strb_ss;
  sc_signal<bool> strb_mm;
  sc_signal<bool> strb_hh;

  sc_signal<bool> dump; // dummy connection for hours overflow strobe

  sc_signal<T> overflow_ss;
  sc_signal<T> overflow_mm;
  sc_signal<T> overflow_hh;

  sc_signal<T> cnt_ss;
  sc_signal<T> cnt_mm;
  sc_signal<T> cnt_hh;

  sc_signal<T> init_ss;
  sc_signal<T> init_mm;
  sc_signal<T> init_hh;

  sc_signal<T> out;

  stimGen sg("Stimuli");
  sg.start = 5; // how long is reset true

  // port binding
  sg.reset(reset);
  sg.enabled(enabled);
  sg.increment_mode(increment_mode);
  sg.strb_ss(strb_ss);

  sg.init_ss(init_ss);
  sg.init_mm(init_mm);
  sg.init_hh(init_hh);

  sg.overflow_ss(overflow_ss);
  sg.overflow_mm(overflow_mm);
  sg.overflow_hh(overflow_hh);

  sg.clock(clk);

  counter co_ss("Seconds");
  co_ss.clock(clk);
  co_ss.reset(reset);
  co_ss.enabled(enabled);
  co_ss.increment_mode(increment_mode);
  co_ss.strobe(strb_ss);
  co_ss.init(init_ss);
  co_ss.overflow_strobe(strb_mm);
  co_ss.overflow(overflow_ss);
  co_ss.out(cnt_ss);

  counter co_mm("Minutes");
  co_mm.clock(clk);
  co_mm.reset(reset);
  co_mm.increment_mode(increment_mode);
  co_mm.strobe(strb_mm);
  co_mm.enabled(enabled);
  co_mm.overflow(overflow_mm);
  co_mm.init(init_mm);
  co_mm.overflow_strobe(strb_hh);
  co_mm.out(cnt_mm);

  counter co_hh("Hours");
  co_hh.clock(clk);
  co_hh.reset(reset);
  co_hh.enabled(enabled);
  co_hh.increment_mode(increment_mode);
  co_hh.strobe(strb_hh);
  co_hh.init(init_hh);
  co_hh.overflow(overflow_hh);
  co_hh.overflow_strobe(dump);
  co_hh.out(cnt_hh);

  // instantiate display
  clockDisplay dis("Display");
  dis.ss(cnt_ss);
  dis.mm(cnt_mm);
  dis.hh(cnt_hh);
  dis.sock = &sock;

  // Tracing
  sc_trace_file *trf = sc_create_vcd_trace_file("counter");
  sc_trace(trf, reset, "reset");
  sc_trace(trf, out, "out");

  // Go
  int cycles = 600; // set number of cycles to simulate
  sc_time st(cycles * 10 + 10, SC_NS);
  cout << "-I- Start of simulation" << endl;
  sc_start(st);

  sc_close_vcd_trace_file(trf);

  return 0;
}
