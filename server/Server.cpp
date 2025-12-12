#include "Server.hpp"

Server::Server() {}

Server::Server(std::string port, std::string password) {
    this->port = atoi(port.c_str());
    this->password = password;
}

Server::Server(const Server &obj) {
    
    serverSocket = obj.serverSocket;
    // clients = obj.clients;
    // channels = obj.channels;
    fds = obj.fds;
}

Server &Server::operator=(const Server &obj) {
    
    if (&obj != this) {
        serverSocket = obj.serverSocket;
        // clients = obj.clients;
        // channels = obj.channels;
        fds = obj.fds;
    }
    return (*this);
}

Server::~Server() {}

void Server::Start(){

    this->ServerStatus = true;
    int pollRes;

    while(ServerStatus)
    {
        std::cout << "Hello" << std::endl;
        pollRes = poll(fds.data(), fds.size(), 500);
        if (pollRes == 0){
            continue;
        }
        else if (pollRes < 0)
        {
            if (errno == EINTR)
                std::cout << "Interrupted system call" << std::endl;
            else
            {
                std::cout << strerror(errno) << std::endl;
                errno;
            }
            break;
        } 
    }
}

void Server::setup() {
    
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    
    int opt = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    fcntl(sock, F_SETFL, O_NONBLOCK);
    sockaddr_in serv;
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(port);

    bind(sock, (sockaddr*)&serv, sizeof(serv));

    listen(sock, 10);

    pollfd temp;
    temp.fd = sock;
}
