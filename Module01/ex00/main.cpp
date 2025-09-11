



#include "Zombie.hpp"



int main(int argc, char *argv[])
{
    Zombie* z1 = newZombie("Foo");

    z1->announce();

    delete(z1);

    randomChump("bar");

    return (0);
}




