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
    
    int yes = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
    
    fcntl(sock, F_SETFL, O_NONBLOCK);

    sockaddr_in serv{};
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(8080);

    bind(sock, (sockaddr*)&serv, sizeof(serv));

    listen(sock, 10);
}
