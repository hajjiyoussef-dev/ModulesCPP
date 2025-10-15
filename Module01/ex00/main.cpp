
#include "Zombie.hpp"



int main(void)
{
    Zombie* z1 = newZombie("Foo");

    z1->announce();

    delete(z1);

    randomChump("bar");

    return (0);
}




