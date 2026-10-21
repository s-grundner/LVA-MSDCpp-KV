#include "cloud.hpp"

/* add server, returns id */
unsigned int Cloud::add(std::string name, unsigned int nCores, uint32_t diskSize, uint32_t ip) {

    /* allocated a cloudServer dynamically */
    CloudServer *cloudServer = new CloudServer(name, nCores, diskSize, ip);

    /* add cloudServer to vector */
    cloudServers.push_back(cloudServer);

    /* return id (index of new cloudServer in vector) */
    return cloudServers.size() - 1;
}

/* return true if the server was removed correctly */
bool Cloud::remove(unsigned int serverid) {

    /*
   * Note:
   * To keep the id's intact, we never erase elements from the vector,
   * instead we simply set the respective entry pointer to null.
   *
   * Alternative: e.g. map instead of a vector
   */

    /* check if serverid is a valid index */
    if (serverid > cloudServers.size() - 1)
        return false;

    /* get cloudServer pointer for serverid */
    CloudServer *cloudServer = cloudServers[serverid];

    /* check, if serverid is valid (pointer is not set to null) */
    if (cloudServer == nullptr)
        return false;


    /* we have found a valid cloudServer */

    /* free memory */
    delete cloudServer;

    /* set entry for id to null */
    cloudServers[serverid] = nullptr;

    /* success */
    return true;
}

/*
 * Print stats
 * (see Exercise 1: computer)
 * implementation in cloud.cpp
 */
void Cloud::printStats()
{
    /* call run for all (valid) cloudServers */
    for (CloudServer *cloudServer : cloudServers) {
        if (cloudServer == nullptr)
            continue;
        cloudServer->printStats();
    }
}

/*
 * Start(process run time)
 * (see Exercise 1: computer)
 */
void Cloud::start(unsigned int runTime)
{
    /* call run for all (valid) cloudServers */
    for (CloudServer *cloudServer : cloudServers) {
        if (cloudServer == nullptr)
            continue;
        cloudServer->start(runTime);
    }
}

/*
 * Execute
 *  * Executes one step for each core, returns true if process finished, else false
 *  * Prints number fo remaining time
 * (see Exercise 1: computer)
 */
bool Cloud::execute() {

    /*
   * call executed for all (valid) cloudServers
   * stop, if execute of a cloudServer returns false
   */
    for (CloudServer *cloudServer : cloudServers) {
        if (cloudServer == nullptr)
            continue;
        if (!cloudServer->execute())
            return false;
    }
    return true;
}
