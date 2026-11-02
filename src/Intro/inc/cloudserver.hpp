#pragma once

#include "computer.hpp"

/* CloudServer inherits from Computer */
class CloudServer : public Computer {

private:
    /* Ip */
    uint32_t ip;
    /* amount of data stored */
    uint32_t storedSize;

public:
    /*
   * Constructor using initializer list
   * (calls the super constructor (Computer))
   */
    CloudServer(std::string name, unsigned int nCores, uint32_t diskSize, uint32_t ip) :
        Computer(name, nCores, diskSize),
        ip(ip) {

        storedSize = 0;
    }

    /*
   * Print stats (overloaded)
   * implementation in cloudserver.cpp
   */
    void printStats();

    /*
   * Increases the amount of data stored by size and returns true if there was enough space left
   * implementation in cloudserver.cpp
   */
    bool store(uint32_t size);

    /*
   * Decreases the amount of data stored
   * implementation in cloudserver.cpp
   */
    void free(uint32_t size);
};
