#pragma once

/* std::string */
#include <string>
/* std::cout */
#include <iostream>
/* uint32_t (Exercise 2) */
#include <cstdint>

class Computer {

private:
    /* Name */
    std::string name;
    /* Number of cores */
    unsigned int nCores;
    /* Disk size (Exercise 2: uint32_t) */
    uint32_t diskSize;

    unsigned int runTime;

public:
    /* Constructor to set up information */
    Computer(std::string name, unsigned int nCores, uint32_t diskSize) {
        this->name = name;
        this->nCores = nCores;
        this->diskSize = diskSize;
        runTime = 0;
    }

    /* Get diskSize (for Exercise 2) */
    uint32_t getDiskSize() {
        return diskSize;
    }

    /*
   * Print stats
   * implementation in computer.cpp
   */
    void printStats();

    /* Start(process run time) */
    void start(unsigned int runTime) {
        this->runTime = runTime;
    }

    /*
   * Execute
   *  * Executes one step for each core, returns true if process finished, else false
   *  * Prints number fo remaining time
   * implementation in computer.cpp
   */
    bool execute();
};
