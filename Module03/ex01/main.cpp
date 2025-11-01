#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
    ClapTrap a("joni");
    ClapTrap b("Bob");
    ScavTrap s1("nk7");
    
    a.attack("Bob");
    b.takeDamage(3);
    b.beRepaired(1);
    b.attack("joni");
    a.takeDamage(3);
    a.beRepaired(1);
    s1.attack("joni");
    s1.takeDamage(3);
    s1.beRepaired(1);

    return 0;
}
