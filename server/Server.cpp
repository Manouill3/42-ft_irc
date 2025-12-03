#include "Server.hpp"

Server::Server() {}

Server::Server(const Server &obj) {
    serverSocket = obj.serverSocket;
    clients = obj.clients;
    channels = obj.channels;
    fds = obj.fds;
}

Server &Server::operator=(const Server &obj) {
    if (&obj != this) {
        serverSocket = obj.serverSocket;
        clients = obj.clients;
        channels = obj.channels;
        fds = obj.fds;
    }
    return (*this);
}

Server::~Server() {}


