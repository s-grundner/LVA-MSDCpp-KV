#include "cloudserver.hpp"

/* Print stats */
void CloudServer::printStats() {
    /* call super method */
    Computer::printStats();

    /* add output specific to CloudServer */
    std::cout << "Stored: " << storedSize << std::endl;
    std::cout << "-------------------------" << std::endl;
}

/* Increases the amount of data stored by size and returns true if there was enough space left */
bool CloudServer::store(uint32_t size) {

    /* enough space? */
    if (storedSize + size > getDiskSize())
        return false;

    storedSize += size;
    return true;
}

/* Decreases the amount of data stored */
void CloudServer::free(uint32_t size) {

    if (size < storedSize)
        storedSize -= size;
    else
        storedSize = 0;
}
