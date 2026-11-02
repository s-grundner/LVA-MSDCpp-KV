#pragma once

#include <vector>

#include "cloudserver.hpp"

/* Cloud contains CloudServers */
class Cloud {

private:
    /* cloudServers vector */
    std::vector<CloudServer *> cloudServers;

public:
    /*
   * add server, returns id
   * implementation in cloud.cpp
   */
    unsigned int add(std::string name, unsigned int nCores, uint32_t diskSize, uint32_t ip);

    /*
   * return true if the server was removed correctly
   * implementation in cloud.cpp
   */
    bool remove(unsigned int serverid);

    /*
   * Print stats
   * (see Exercise 1: computer)
   * implementation in cloud.cpp
   */
    void printStats();

    /*
   * Start(process run time)
   * (see Exercise 1: computer)
   * implementation in cloud.cpp
   */
    void start(unsigned int runTime);

    /*
   * Execute
   *  * Executes one step for each core, returns true if process finished, else false
   *  * Prints number fo remaining time
   * (see Exercise 1: computer)
   * implementation in cloud.cpp
   */
    bool execute();
};
