#include "Server.hpp"

Server::Server(){   }

Server::Server(int port, std::string password) : _port(port), _password(password) { }

Server::Server(const Server& obj){
        _port = obj._port;
        _password = obj._password;
}

Server& Server::operator=(const Server &obj){
    if (this != &obj)
    {
        _port = obj._port;
        _password = obj._password;
    }
    return (*this);
};

Server::~Server(){  };

void    Server::start(){
    _serverRun = true;
    pollfd FdStart;
    while(_serverRun)
    {
        _serverSocket = poll(FdStart.fd, )
    }

}