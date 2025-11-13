#include "DiamondTrap.hpp"



DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), name("name") {

    hitPoint = FragTrap::hitPoint;
    Energy = ScavTrap::Energy;
    AttackDamage = FragTrap::AttackDamage;
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), name(name) {

    hitPoint = FragTrap::hitPoint;
    Energy = ScavTrap::Energy;
    AttackDamage = FragTrap::AttackDamage;
    std::cout << "DiamondTrap " << this->name << " constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) :
    ClapTrap(obj),
    ScavTrap(obj),
    FragTrap(obj)
{
    *this = obj;
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap  &DiamondTrap::operator=(const DiamondTrap &obj)
{
    if (this != &obj){
        ClapTrap::operator=(obj);
        name = obj.name;
    }
    return (*this);
}


DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI( void ){

    std::cout << "I am " << name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}

