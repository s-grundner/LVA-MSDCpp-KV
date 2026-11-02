#include "stimGen.h"
#include <unistd.h>

int read_keyboard_input() {
  puts("Increment counter (w), decrement counter (s), or quit (q):");
  system("stty raw");
  int k = getchar();
  system("stty cooked");
  return k;
}

void stimGen::calc() {

  while (start > 0) {
    reset.write(true);
    start--;
    wait();
  }

  reset.write(false);
  enabled.write(true);
  increment_mode.write(true);

  for (int i = 0; i < 20; ++i) {
    usleep(200000);
    wait();
  }

  int k = 0;
  while (k != 'q') {
    // additional delay to ensure that counter is not driven by old values
    enabled.write(false);
    wait(); 
    enabled.write(true);

    k = read_keyboard_input();
    switch (k) {
    case 'w':
      increment_mode.write(true);
      break;
    case 's':
      increment_mode.write(false);
      break;
    default:
      enabled.write(false);
    }
    wait();
  }
}

stimGen::stimGen(sc_module_name) {
  SC_THREAD(calc);
  sensitive << clock.pos();
}
