/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:42:40 by yhajji            #+#    #+#             */
/*   Updated: 2025/10/25 22:39:19 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


void Zombie::SetZombieName(std::string value){
    zombie = value;
}

Zombie::Zombie(){ }

Zombie::~Zombie(){
    std::cout << "Zombie " << zombie << " is destroyed" << std::endl;
}

void Zombie::announce(void){
    std::cout << zombie << ": BraiiiiiiinnnzzzZ..." << std::endl ;
}


Zombie* zombieHorde(int n, std::string name){
    Zombie* zo = new Zombie[n];
    for (int i = 0; i < n; i++){
        zo[i].SetZombieName(name);
    }
    return (zo);
}

