#ifndef K3B4TESTBENCH_H
#define K3B4TESTBENCH_H
#include <systemc>
using namespace sc_core;
using namespace sc_dt;	 //SC data types

struct Testbench : public sc_module {
	//Ports
	sc_in<bool>		clk;
	sc_in<sc_int<8>>	dataIn;
	sc_out<sc_lv<2>>	mode;
	sc_out<sc_uint<4>>	distance;
	sc_out<sc_int<8>>	opA, opB;
	//Processes
	void generateStimuli();
	//Constructor
	SC_HAS_PROCESS(Testbench);
	Testbench(sc_module_name);
};
#endif
