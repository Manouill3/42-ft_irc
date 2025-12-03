#include "Server.hpp"

Server::Server() 
{

}

void    Server::socket()
{
    _serverSocket = socket(AF_INET, SOCK_STREAM, 0);
}

Server::Server(const Server& other)
{
     _serverSocket = other._serverSocket;
}

Server& Server::operator=(const Server& other)
{
    if (&other != this)
    {
         _serverSocket = other._serverSocket;
    }
    return (*this);
}

Server::~Server()
{

} 