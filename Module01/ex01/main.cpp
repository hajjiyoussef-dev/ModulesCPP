/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:24:02 by yhajji            #+#    #+#             */
/*   Updated: 2025/10/17 18:44:28 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){

    int N = 5;

    if (N <= 0)
        return 1;
    Zombie* z1 = zombieHorde(N, "Walker");
    
    for (int i = 0; i < 5; i++){
        z1[i].announce();
    }
    delete[] z1;
    return (0);
}