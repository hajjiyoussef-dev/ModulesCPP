#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

// int main()
// {
// IMateriaSource* src = new MateriaSource();
// src->learnMateria(new Ice());
// src->learnMateria(new Cure());
// ICharacter* me = new Character("me");
// AMateria* tmp;
// tmp = src->createMateria("ice");
// me->equip(tmp);
// tmp = src->createMateria("cure");
// me->equip(tmp);
// for (int )
// ICharacter* bob = new Character("bob");
// me->use(0, *bob);
// me->use(1, *bob);
// delete bob;
// delete me;
// delete src;
// return 0;
// }


// int main()
// {
// IMateriaSource* src = new MateriaSource();
// src->learnMateria(new Ice());
// src->learnMateria(new Cure());
// for (int i = 0; i < 10000; i++)
// {
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
// }
// ICharacter* me = new Character("me");
// AMateria* tmp;
// tmp = src->createMateria("ice");
// me->equip(tmp);
// tmp = src->createMateria("cure");
// me->equip(tmp);
// ICharacter* bob = new Character("bob");
// me->use(0, *bob);
// me->use(1, *bob);
// delete bob;
// delete me;
// delete src;
// return 0;
// }


int main()
{
    IMateriaSource* src = new MateriaSource();
    AMateria *material[4];
    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0)
            material[i] = new Ice();
        else
            material[i] = new Cure();
        src->learnMateria(material[i]);
    }

    ICharacter* me = new Character("me");
    AMateria* tmp, *tmp1, *tmp2 , *tmp3, *t1;
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp1 = src->createMateria("cure");
    // me->equip(tmp1);
    // tmp2 = src->createMateria("ice");
    // me->equip(tmp2);
    // tmp3 = src->createMateria("cure");
    // me->equip(tmp3);
    //
    // for (int i = 0; i < 1000; i++)
    // {
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp1 = src->createMateria("cure");
        me->equip(tmp1);
        tmp2 = src->createMateria("ice");
        me->equip(tmp2);
        tmp3 = src->createMateria("cure");
        me->equip(tmp3);
        t1 = src->createMateria("cure");
        me->equip(t1);

    // }
    // delete tmp;
    // delete tmp1;
    // delete tmp2;
    // delete tmp3;
    ICharacter* bob  =  new Character("bob");
    ICharacter* bob1 =  new Character("bob1");
    ICharacter* bob2 =  new Character("bob2");
    ICharacter* bob3 =  new Character("bob3");
    ICharacter* bob4 =  new Character("bob3");
    me->use(0, *bob);
    me->use(1, *bob1);
    me->use(2, *bob2);
    me->use(3, *bob3);
    me->use(3, *bob4);
    
    delete bob;
    delete bob1;
    delete bob2;
    delete bob3;
    delete bob4;
    delete me;
    delete src;
    for (int i = 0; i < 4; i++)
        delete material[i];
    return (0);
}

