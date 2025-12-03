/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:04:45 by tcybak            #+#    #+#             */
/*   Updated: 2025/12/03 14:09:53 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

Server::Server() 
{
    
}

Server::Server(const Server& other)
{
    _map = other._map;
}

Server& Server::operator=(const Server& other)
{
    if (&other != this)
    {
        _map = other._map;
    }
    return (*this);
}

Server::~Server()
{
    
} 