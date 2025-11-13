#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"



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
    AMateria* tmp, *tmp1, *tmp2 , *tmp3;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp1 = src->createMateria("cure");
    me->equip(tmp1);
    tmp2 = src->createMateria("ice");
    me->equip(tmp2);
    tmp3 = src->createMateria("cure");
    me->equip(tmp3);
    me->unequip(1); 
    delete tmp1;
    me->equip(tmp2);
    // me->unequip(3);
    // delete tmp3;
    ICharacter* bob = new Character("bob");
    ICharacter* bob1 = new Character("HHH1");
    ICharacter* bob2 = new Character("HHH2");
    ICharacter* bob3 = new Character("HHH3");
    me->use(0, *bob);
    me->use(1, *bob1);
    me->use(2, *bob2);
    me->use(3, *bob3);
    
    delete bob;
    delete bob1;
    delete bob2;
    delete bob3;
    delete me;
    delete src;
    for (int i = 0; i < 4; i++)
        delete material[i];
    return (0);
}