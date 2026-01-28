 #ifndef CLIENT_HPP
 #define CLIENT_HPP

#include <iostream>
#include <set>

enum State {

    Not_connected,
    Password_sent,
    Registering,
    Registered
};

class Client {

    private :

        int ClientSocket;
        State state;
        std::set<std::string> enabledCaps;
        bool capNegociating;
        bool passwordAuthenticated;
        std::string nickname;
        std::string username;
        std::string realname;
        std::string hostname;
        std::string buffer;

    public :

        

};

 #endif //client.hpp