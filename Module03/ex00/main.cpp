
#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap a("joni");
    ClapTrap b("Bob");
    
    a.attack("Bob");
    b.takeDamage(3);
    b.beRepaired(1);
    b.attack("joni");
    a.takeDamage(3);
    a.beRepaired(1);
    
    return 0;
}
