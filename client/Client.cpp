#include "Client.hpp"

Client::Client(){   }

Client::Client(const Client &obj){

    socketfd = obj.socketfd;
    isRegistered = obj.isRegistered;
    nickname = obj.nickname;
    username = obj.username;
    realname = obj.realname;
    buffer = obj.buffer;
}

Client &Client::operator=(const Client &obj){

    if (&obj != this) {
        socketfd = obj.socketfd;
        isRegistered = obj.isRegistered;
        nickname = obj.nickname;
        username = obj.username;
        realname = obj.realname;
        buffer = obj.buffer;
    }
    return (*this);
}

Client::~Client() { }