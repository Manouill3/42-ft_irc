
#ifndef SERVER_HPP
#define SERVER_HPP

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstring>
#include <iostream>


class Server
{
    public:
        Server();
        Server(const Server& other);
        Server&     operator=(const Server& other);
        void        socket();
        ~Server();
    private:
        int _serverSocket;
        
    
};




#endif