#include "computer.hpp"
#include "cloudserver.hpp"
#include "cloud.hpp"

int main() {

    std::cout << "\n### Exercise 1 ###\n" << std::endl;

    /* Instanciate Computer (Automatic) */
    Computer computer("CPU 1", 1, 1024);

    computer.printStats();
    computer.start(10);

    /* execute until finished (return false) */
    while(computer.execute());


    std::cout << "\n\n### Exercise 2 ###\n" << std::endl;

    /* Instanciate CloudServer (Automatic) */
    CloudServer cloudServer(
        "CloudServer 1",
        2, /* 2 cores */
        1024,
        (10<<24|1<<16|1<<8|20<<0) 	/* ip 10.1.1.20 */
    );

    cloudServer.printStats();
    cloudServer.start(10);

    /* execute until finished (return false) */
    while(cloudServer.execute());

    /* store until full */
    std::cout << std::endl;
    while(true) {
        cloudServer.printStats();
        std::cout << "store 300 bytes -> ";
        if (cloudServer.store(300))
            std::cout << "success" << std::endl;
        else {
            std::cout << "fail" << std::endl;
            break;
        }
    }

    /* free */
    std::cout << std::endl;
    cloudServer.printStats();
    std::cout << "free 500 bytes" << std::endl;
    cloudServer.free(500);
    cloudServer.printStats();


    std::cout << "\n\n### Exercise 3 ###\n" << std::endl;

    Cloud cloud;
    int ids[3];

    std::cout << "Add three cloud servers" << std::endl;
    ids[0] = cloud.add("CloudServer 1", 1, 1024, (10<<24|1<<16|1<<8|100<<0));
    ids[1] = cloud.add("CloudServer 2", 2, 1024, (10<<24|1<<16|1<<8|101<<0));
    ids[2] = cloud.add("CloudServer 3", 2, 1024, (10<<24|1<<16|1<<8|102<<0));
    cloud.printStats();

    for (int i = 0; i < 2; i++) {
        std::cout << "Remove \"CloudServer 2\" (" << i << ") -> ";
        if (cloud.remove(ids[1]))
            std::cout << "success" << std::endl;
        else
            std::cout << "fail" << std::endl;
    }
    cloud.printStats();

    std::cout << "Run cloud for 10 steps" << std::endl;
    cloud.start(10);

    /* execute until finished (return false) */
    while(cloud.execute());

    std::cout << "\n\ndone.\n" << std::endl;
}
