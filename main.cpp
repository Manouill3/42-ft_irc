#include "Server.hpp"

int main(int ac, char **av) {
    
    if (ac != 3) {
        std::cout << "ERROR : Wrong number of argument !" << std::endl;
        std::cout << "Good format = ./ircserv <port> <password>" << std::endl;
        return 1;
    }
    
}