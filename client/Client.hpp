 #ifndef CLIENT_HPP
 #define CLIENT_HPP

#include <iostream>
#include <set>

enum State {

    NOT_CONNECTED,
    PASSWORD_SENT,
    REGISTERING,
    REGISTERED
};

class Client {

    private :

        int ClientSocket;
        State state;
        std::set<std::string> enabledCaps;
        bool capNegociated;
        bool passwordAuthenticated;
        std::string nickname;
        std::string username;
        std::string realname;
        std::string hostname;
        std::string buffer;

    public :

        Client();
        Client(int fd);
        Client(const Client &obj);
        Client &operator=(const Client &obj);
        ~Client();

        int get_ClientSocket() const;
        bool is_register() const;
        bool get_authentificated() const;
        bool get_capNegociated() const;
        const std::string get_nickname() const;
        const std::string get_username() const;
        const std::string get_realname() const;
        const std::string get_hostname() const;
        const std::string get_buffer() const;
        State getState() const;

        void set_capNegociated(bool negociated);
        void set_authentificated(bool authentificate);
        void set_nickname(std::string nickname);
        void set_username(std::string username);
        void set_realname(std::string realname);
        void set_hostname(std::string hostname);
        void setState(State newState);
        
};

 #endif