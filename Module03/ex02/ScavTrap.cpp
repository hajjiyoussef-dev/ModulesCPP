#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap() {

    std::cout << "ScavTrap default constructor called" << std::endl;
    hitPoint = 100;
    Energy = 50;
    AttackDamage = 20;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    hitPoint = 100;
    Energy = 50;
    AttackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj){
    
    hitPoint = obj.hitPoint;
    Energy = obj.Energy;
    AttackDamage = obj.AttackDamage;
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj){

    if (this != &obj)
        ClapTrap::operator=(obj);
    return (*this);
}
void ScavTrap::attack(const std::string& target)
{
    if (Energy > 0 && hitPoint > 0)
    {
        std::cout << "ScavTrap " << name << " fiercely attacks " << target
                  << ", causing " << AttackDamage << " points of damage!" << std::endl;
        Energy--;
    }
    else
        std::cout << "ScavTrap " << name << " is too tired or dead to attack..." << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << this->name << " is in guard mode"<< std::endl;
}

ScavTrap::~ScavTrap(){

    std::cout << "ScavTrap Destructor called" << std::endl;

}
