#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int ac, char **av) {
    
    if (ac != 3) {
        std::cout << "ERROR : Wrong number of argument !" << std::endl;
        std::cout << "Good format = ./ircserv <port> <password>" << std::endl;
        return 1;
    }

}