#include "FragTrap.hpp"


int main( void ){

    FragTrap frag("Fraggy");
    frag.attack("Enemy3");
    frag.takeDamage(30);
    frag.beRepaired(20);
    frag.highFivesGuys();

}