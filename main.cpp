#include "server/Server.hpp"
#include "client/Client.hpp"

int main(int ac, char **av) {
    
    if (ac != 3) {
        std::cout << "ERROR : Wrong number of argument !" << std::endl;
        std::cout << "Good format = ./ircserv <port> <password>" << std::endl;
        return 1;
    }

    Server serv(av[1], av[2]);
    serv.start();
}