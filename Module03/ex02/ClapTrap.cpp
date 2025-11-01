#include "ClapTrap.hpp"


ClapTrap::ClapTrap(){

    std::cout << "Default constructor called" << std::endl;
    this->hitPoint = 100;
    this->Energy =  50;
    this->AttackDamage = 20;
}

ClapTrap::ClapTrap(std::string name) : name(name){
    this->hitPoint = 100;
    this->Energy =  50;
    this->AttackDamage = 30;
    std::cout << "ClapTrap constructor called" << std::endl; 
}

ClapTrap::~ClapTrap(){

    std::cout << "Destructor called" << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap &obj) : 
    name(obj.name), 
    hitPoint(obj.hitPoint),
    Energy(obj.Energy),
    AttackDamage(obj.AttackDamage)
{
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap  &ClapTrap::operator=(const ClapTrap &obj){

    if (this != &obj)
    {
        name = obj.name;
        AttackDamage = obj.AttackDamage;
        Energy = obj.Energy;
        hitPoint = obj.hitPoint;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (Energy <= 0 || hitPoint <= 0)
    {
        std::cout << "Claptrap " << name << "can t attack !" << std::endl;
        return ;
    }

    Energy--;
    std::cout << "ClapTrap " << name << " attack " << target << ", causing "
        << AttackDamage << " points of damage! " << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    
    if (hitPoint <= 0)
    {
        std::cout << " Claptrap " << name << " is already destroyed!" << std::endl;
        return ;
    }

    if (amount >= hitPoint)
        hitPoint = 0;
    else 
        hitPoint -= amount;
    
    std::cout << "ClapTrap " << name
              << " takes " << amount << " damage! "
              << "Remaining hit points: " << hitPoint << std::endl;
    if (hitPoint == 0)
        std::cout << "Claptrap " << name << " is already destroyed!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){

    if (Energy <= 0 || hitPoint <= 0)
    {
        std::cout << "ClapTrap " << name << " can t repair itself!" << std::endl;
        return ;
    }
    Energy--;
    hitPoint += amount;
    std::cout   << "ClapTrap " << name << " repairs itself, recovering " << amount 
                << " hit points! Now has " << hitPoint << " HP ." << std::endl ;

}