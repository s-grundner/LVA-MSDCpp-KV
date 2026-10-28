#include "stimGen.h"
#include <ctime>
#include <unistd.h>

#define SECONDS_PER_MINUTE 60
#define MINUTES_PER_HOUR 60
#define HOURS_PER_DAY 24

int read_keyboard_input() {
  // puts("Increment counter (w), decrement counter (s), or quit (q):");
  system("stty raw");
  int k = getchar();
  system("stty cooked");
  return k;
}

void stimGen::calc() {

  time_t timestamp = time(&timestamp);
  struct tm datetime = *localtime(&timestamp);

  while (start > 0) {
    reset.write(true);
    start--;
    wait();
  }

  init_ss.write(datetime.tm_sec);
  init_mm.write(datetime.tm_min);
  init_hh.write(datetime.tm_hour);
  wait();

  overflow_ss.write(SECONDS_PER_MINUTE);
  overflow_mm.write(MINUTES_PER_HOUR);
  overflow_hh.write(HOURS_PER_DAY);
  wait();

  reset.write(false);
  enabled.write(true);
  increment_mode.write(true);
  wait();

  while (true) {
    usleep(1000000); // 1s
    // Pulse Seconds-Strobe for 1 clock cycle
    strb_ss.write(true);
    wait();
    strb_ss.write(false);
    wait();
  }
}

stimGen::stimGen(sc_module_name) {
  SC_THREAD(calc);
  sensitive << clock.pos();
}
