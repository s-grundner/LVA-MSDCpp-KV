#include <systemc>
using namespace sc_core;
#include "k3b4alu.h"
#include "k3b4testbench.h"
#include <iostream>
using namespace std;

int sc_main(int argc, char *argv[]) {

	sc_clock clk("clk", 10, SC_NS);
	Alu dut("dut");
	Testbench tb("tb");

	sc_signal<sc_int<8>> opA, opB, result;
	sc_signal<sc_uint<4>> distance;
	sc_signal<sc_lv<2>> mode;

	tb.clk(clk);
	tb.dataIn(result);
	tb.opA(opA);
	tb.opB(opB);
	tb.mode(mode);
	tb.distance(distance);

	dut.clk(clk);
	dut.opA(opA);
	dut.opB(opB);
	dut.result(result);
	dut.mode(mode);
	dut.distance(distance);

	//Create trace file
	sc_trace_file *fp;
	fp = sc_create_vcd_trace_file("traces");
	sc_trace(fp, clk, "clk");
	sc_trace(fp, opA, "opA");
	sc_trace(fp, opB, "opB");
	sc_trace(fp, mode, "mode");
	sc_trace(fp, distance, "distance");
	sc_trace(fp, result, "result");

	//Start simulation
	sc_start(65, SC_NS);

	//Close trace file
	sc_close_vcd_trace_file(fp);

	return 0;
}
