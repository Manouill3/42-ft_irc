 #ifndef CLIENT_HPP
 #define CLIENT_HPP

#include <iostream>

class Client {

private :

    int clientSocket;
    bool isRegistered;
    std::string hostname;
    std::string nickname;
    std::string username;
    std::string realname;
    std::string buffer;

public :

    Client();
    Client(int fd);
    Client(const Client &obj);
    Client &operator=(const Client &obj);
    ~Client();

    int getSocketFd() const;
    const std::string &getNickname() const;
    const std::string &getUsername() const;
    const std::string &getRealname() const;
    const std::string &getHostname() const;
    const std::string &getBuffer() const;

    void setNickname(const std::string &nickname);
    void setUsername(const std::string &username);
    void setRealname(const std::string &realname);
    void setHostname(const std::string &hostname);
    // void setPasswordAuthenticated(bool auth);
    // void setCapNegotiating(bool negotiating);
};

 #endif //client.hpp