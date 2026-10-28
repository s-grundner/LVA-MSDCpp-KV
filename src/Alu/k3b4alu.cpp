#include "k3b4alu.h"
#include <iostream>
using namespace std;
// Constructor
Alu::Alu(sc_module_name name) {
  SC_THREAD(aluProcess);
  sensitive << clk.pos();
}
// Process
void Alu::aluProcess() {
  sc_int<8> aluReg(0);

  while (1) {
    aluReg = opA.read();
    cout << "Time: " << sc_time_stamp();
    cout << ", Mode: " << mode.read();
    cout << ", OperandA: " << aluReg;
    cout << ", OperandB: " << opB.read();
    cout << ", distance: " << distance.read();

    switch (mode.read().to_uint()) {
    case 0: // 00: addition of opA and opB
      aluReg += opB.read();
      break;
    case 1: // 01: shift opA by distance
      aluReg = opA.read() << distance.read();
      break;
    case 2: // 10: left rotation of opA by 1
      aluReg = (opA.read() << 1) | ((opA.read() & 0x80) >> 7);
      break;
    case 3: // 11: subtraction of opB from opA
      aluReg -= opB.read();
      break;
    default:
      break;
    }

    cout << ", Result: " << aluReg << endl;
    result.write(aluReg);
    wait();
  }
}
