#include "computer.hpp"

/* Print stats */
void Computer::printStats() {
    std::cout << "-------------------------" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Cores: " << nCores << std::endl;
    std::cout << "Disk: " << diskSize << std::endl;
    std::cout << "-------------------------" << std::endl;
}

/*
 * Execute
 *  * Executes one step for each core, returns true if process finished, else false
 *  * Prints number fo remaining time
 */
bool Computer::execute() {
    if (runTime == 0)
        return false;

    runTime--;
    for (unsigned int core = 0; core < nCores; core++)
        std::cout << name << ": remaining task length: " << runTime << std::endl;
    return true;
}
