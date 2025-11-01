
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
        
    std::cout << "FragTrap default constructor called" << std::endl;
    hitPoint =  100;
    Energy = 100;
    AttackDamage = 30;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name){

    std::cout << "FragTrap constructor called" << std::endl;
    hitPoint =  100;
    Energy =  100;
    AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj){

    std::cout << "FragTrap Copy constructor called" << std::endl;
    hitPoint = obj.hitPoint;
    Energy = obj.Energy;
    AttackDamage = obj.AttackDamage;
}

FragTrap &FragTrap::operator=(const FragTrap &obj){

    if (this != &obj)
        ClapTrap::operator=(obj);
    return (*this);
}

void FragTrap::highFivesGuys( void ){

    std::cout << "FragTrap " << name << " requests a positive high five! 🙌" << std::endl;
}

FragTrap::~FragTrap(){

    std::cout << "FragTrap Destructor called" << std::endl;
}