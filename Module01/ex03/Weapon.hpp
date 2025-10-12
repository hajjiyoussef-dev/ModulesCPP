/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:33:56 by yhajji            #+#    #+#             */
/*   Updated: 2025/10/12 10:05:26 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H


#include <iostream>


class Weapon
{
    private:
        std::string type;
    
    public:
        Weapon(std::string type);
    std::string getType(void);
    void setType(std::string value);
    
};

#endif