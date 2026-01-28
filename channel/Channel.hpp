#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <iostream>
#include <vector>

#include "../client/Client.hpp"

class Channel {

    private :

        bool inviteOnly;
        bool topicRestricted;
        bool hasKey;
        bool hasUserLimit;
        size_t userLimit;
        std::vector<Client*> members;
        std::vector<Client*> operators;
        std::vector<Client*> inviteList;
        std::string name;
        std::string topic;
        std::string serverIP;
        std::string key;

    public :

        

};

#endif