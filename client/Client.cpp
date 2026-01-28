#include "Client.hpp"

Client::Client() {
    ClientSocket = -1;
    nickname = "";
    username = "";
    realname = "";
    hostname = "";
}

Client::Client(int fd) {
    ClientSocket = fd;
    nickname = "";
    username = "";
    realname = "";
    hostname = "";
}

Client::Client(const Client &obj) {
    ClientSocket = obj.ClientSocket;
    nickname = obj.nickname;
    username = obj.username;
    realname = obj.realname;
    hostname = obj.hostname;
}

Client &Client::operator=(const Client &obj) {
    if (&obj != this) {
        ClientSocket = obj.ClientSocket;
        nickname = obj.nickname;
        username = obj.username;
        realname = obj.realname;
        hostname = obj.hostname;
    }
    return (*this);
}

Client::~Client() {}

int Client::get_ClientSocket() const {return ClientSocket;}
bool Client::is_register() const {return state == REGISTERED;}
bool Client::get_authentificated() const {return passwordAuthenticated;}
bool Client::get_capNegociated() const {return capNegociated;}
const std::string Client::get_nickname() const {return nickname;}
const std::string Client::get_username() const {return username;}
const std::string Client::get_realname() const {return realname;}
const std::string Client::get_hostname() const {return hostname;}
const std::string Client::get_buffer() const {return buffer;}
State Client::getState() const {return state;}

void Client::set_capNegociated(bool negociated) {capNegociated = negociated;}
void Client::set_authentificated(bool authentificate) {passwordAuthenticated = authentificate;}
void Client::set_nickname(std::string nickname) {this->nickname = nickname;}
void Client::set_username(std::string username) {this->username = username;}
void Client::set_realname(std::string realname) {this->realname = realname;}
void Client::set_hostname(std::string hostname) {this->hostname = hostname;}
void Client::setState(State newState) {state = newState;}


