/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:01:46 by tcybak            #+#    #+#             */
/*   Updated: 2025/12/03 14:09:26 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>

class Server
{
    public:
        Server();
        Server(const Server& other);
        Server&         operator=(const Server& other);
        ~Server();
    private:
        int _map;
        
    
};




#endif