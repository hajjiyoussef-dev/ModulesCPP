#include "Character.hpp"



Character::Character(){

    name = "default";
    for (size_t i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(std::string const& name){
    
    this->name = name;
    for (size_t i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const Character & obj){

    *this = obj;
}

Character &Character::operator=(const Character &obj){

    if (this != &obj){
        name = obj.name;
        for (size_t i = 0; i < 4; i++)
        {
            if (inventory[i])
                delete inventory[i];
            if (obj.inventory[i])
                inventory[i] = obj.inventory[i]->clone();
            else 
                inventory[i] = NULL;
        }
    }
    return (*this);
}

std::string const &Character::getName( void ) const {

    return (name);
}

void Character::equip(AMateria *m){

    if (!m)
        return;
    for (size_t i = 0; i < 4; i++)
    {
        if (inventory[i] == m)
            return;
    }
    for (size_t i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            return;
        }
    }

    std::cout << name << " inventory is full!" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target){

    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
}

Character::~Character(){
    for (size_t i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
    }
}