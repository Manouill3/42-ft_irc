
#ifndef SERVER_HPP
#define SERVER_HPP

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <list>
#include <vector>


class Server {

private:
    
    int serverSocket;
    std::list<int> clients;
    std::list<std::string> channels;
    std::vector<int> fds;
    
public:

    Server();
    Server(const Server& obj);
    Server &operator=(const Server& obj);
    ~Server();
    
    
};

#endif