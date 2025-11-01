#ifndef SCRAVTRAP_HPP
#define SCRAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const std::string name);
        ~ScavTrap();
        ScavTrap(const ScavTrap &obj);
        ScavTrap &operator=(const ScavTrap &obj);
        void attack(std::string const &target);
        void guardGate();
   
};





#endif