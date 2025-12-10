
#ifndef SERVER_HPP
#define SERVER_HPP

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
#include "Client.hpp"


class Server {

private:
    
    int port;
    std::string password;

    int serverSocket;
    // std::map<int, *Client> clients;
    // std::map<std::string> channels;
    std::vector<int> fds;
    
public:

    Server();
    Server(std::string port, std::string password);
    Server(const Server& obj);
    Server &operator=(const Server& obj);
    ~Server();
    
    void setup();
};

#endif