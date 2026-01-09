#include "Client.hpp"

Client::Client(){}

Client::Client(int fd) {
    clientSocket = fd;
}

Client::Client(const Client &obj){

    clientSocket = obj.clientSocket;
    isRegistered = obj.isRegistered;
    hostname = obj.hostname;
    nickname = obj.nickname;
    username = obj.username;
    realname = obj.realname;
    buffer = obj.buffer;
}

Client &Client::operator=(const Client &obj){

    if (&obj != this) {
        clientSocket = obj.clientSocket;
        isRegistered = obj.isRegistered;
        nickname = obj.nickname;
        username = obj.username;
        realname = obj.realname;
        buffer = obj.buffer;
    }
    return (*this);
}

Client::~Client() {}

int Client::getSocketFd() const { return clientSocket; }
const std::string &Client::getNickname() const { return nickname; }
const std::string &Client::getUsername() const { return username; }
const std::string &Client::getRealname() const { return realname; }
const std::string &Client::getHostname() const { return hostname; }
const std::string &Client::getBuffer() const { return buffer; }

// ClientState Client::getState() const { return state; }

// bool Client::isPasswordAuthenticated() const { return passwordAuthenticated; }

// bool Client::isRegistered() const { return state == REGISTERED; }

// bool Client::isCapNegotiating() const { return capNegotiating; }

void Client::setNickname(const std::string &nickname) { this->nickname = nickname; }
void Client::setUsername(const std::string &username) { this->username = username; }
void Client::setRealname(const std::string &realname) { this->realname = realname; }
void Client::setHostname(const std::string &hostname) { this->hostname = hostname; }
// void Client::setPasswordAuthenticated(bool auth) { passwordAuthenticated = auth; }
// void Client::setCapNegotiating(bool negotiating) { capNegotiating = negotiating; }

// void Client::appendToBuffer(const std::string &data) { buffer += data; }
// void Client::clearBuffer() { buffer.clear(); }
