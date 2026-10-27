#include "k3b4testbench.h"
#include <iostream>
using namespace std;

//Constructor
Testbench::Testbench(sc_module_name name){
	SC_THREAD(generateStimuli);
	sensitive << clk.neg();	
}

//Process
void Testbench::generateStimuli() {

	wait();
	mode.write(1);		// shift left
	distance.write(4);
	opA.write(1);
	opB.write(0);
	wait();

	mode.write(2);		// rotate
	opA.write(-127);
	wait();

	mode.write(0);		// sum
	opA.write(93);
	opB.write(3);
	wait();

	opA.write(127);
	opB.write(1);
	wait();

	mode.write(3);		// subtract
	wait();

	opA.write(-128);
	opB.write(1);

	wait();
}
