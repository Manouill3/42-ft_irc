
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
#include <stdlib.h>
#include <poll.h>
#include <cerrno>

#include "../client/Client.hpp"


class Server {

private:
    
    int port;
    bool running;
    int serverSocket;
    std::string password;

    std::vector <pollfd> fds;
    std::map<const int, Client*> clients;
    // std::map<std::string> channels;
    
    sockaddr_in serv;

public:

    Server();
    Server(std::string port, std::string password);
    Server(const Server& obj);
    Server &operator=(const Server& obj);
    ~Server();
    
    void setup();
    void start();
    void AcceptNewClient();
    void HandleMessage(int fd);
};

#endif