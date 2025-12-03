 #ifndef CLIENT_HPP
 #define CLIENT_HPP

#include <iostream>

class Client {

private :

    int socketfd;
    bool isRegistered;
    std::string nickname;
    std::string username;
    std::string realname;
    std::string buffer;

public :

    Client();
    Client(const Client &obj);
    Client &operator=(const Client &obj);
    ~Client();
};

 #endif //client.hpp