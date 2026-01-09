#include "Server.hpp"

Server::Server() {}

Server::Server(std::string port, std::string password) {
    this->port = atoi(port.c_str());
    this->password = password;
    setup();
}

Server::Server(const Server &obj) {
    
    port = obj.port;
    password = obj.password;
    serverSocket = obj.serverSocket;
    // clients = obj.clients;
    // channels = obj.channels;
}

Server &Server::operator=(const Server &obj) {
    
    if (&obj != this) {
        port = obj.port;
        password = obj.password;
        serverSocket = obj.serverSocket;
        // clients = obj.clients;
        // channels = obj.channels;
    }
    return (*this);
}

Server::~Server() {}

void Server::setup() {
    
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    
    int opt = 1;
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    fcntl(serverSocket, F_SETFL, O_NONBLOCK);

    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(port);

    bind(serverSocket, (sockaddr*)&serv, sizeof(serv));

    listen(serverSocket, 10);
    
    pollfd tmp;
    tmp.fd = serverSocket;
    fds.push_back(tmp);
}

void Server::start() {
    
    running = true;
    while (running) {
        int activity = poll(fds.data(), fds.size(), 30);
        
        if (activity < 0)
            running = false;

        for (size_t i = 0; i < fds.size(); i++) {
            if (fds[i].revents && POLLIN) {
                if (i == 0)
                    AcceptNewClient();
                // else
                    // HandleMessage(0);
            }
        }
    }
}

void    Server::AcceptNewClient()
{
    sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    int clientSocket = accept(serverSocket, ((sockaddr*)&client_addr), &client_len);
    if (clientSocket < 0)
    {
        std::cout << strerror(errno) << std::endl;
        errno;
    }
    
    Client *newClient = new Client(clientSocket);
    newClient->setHostname(inet_ntoa(client_addr.sin_addr));
    clients[clientSocket] = newClient;

    struct pollfd clientPollFd;
    clientPollFd.fd = clientSocket;
    clientPollFd.events = POLLIN;
    clientPollFd.revents = 0;
    fds.push_back(clientPollFd);
}
 

// void Server::HandleMessage(int fd) {


// }
