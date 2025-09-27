/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:24:28 by yhajji            #+#    #+#             */
/*   Updated: 2025/09/16 12:45:07 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <cctype>


class Zombie
{
    private:
        std::string  zombie;
    
    public:
        Zombie();
        ~Zombie();
    
        void announce(void);
        void SetZombieName(std::string value);
};
    
Zombie* zombieHorde( int N, std::string name ); 







#endif