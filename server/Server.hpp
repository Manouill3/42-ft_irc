
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
#include "../channel/Channel.hpp"

class Server {

    private:
        
        bool _serverRun;
        int _port;
        int _serverSocket;
        std::string _password;
        std::string hostname;
        std::string serverIP;
        std::vector<struct pollfd> fds;
        std::vector<int> ClientToRem;
        std::map<int, Client*> clients;
        std::map<std::string, Channel*> channels;

    public:

        Server();
        Server(int port, std::string password);
        Server(const Server& obj);
        Server &operator=(const Server& obj);
        ~Server();

        void    Server::start();

        
};

#endif