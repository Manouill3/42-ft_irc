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

void Server::setup(char *port, char *password) {
    
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, );
    fcntl(sock, F_SETFL, O_NONBLOCK);
    bind();
}
