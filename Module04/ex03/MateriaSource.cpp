#include "MateriaSource.hpp"



MateriaSource::MateriaSource(){

    for (size_t i = 0; i < 4; i++)
        materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &obj){

    *this = obj;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj){

    if (this != &obj){

        for (size_t i = 0; i < 4; i++)
        {
            if (materias[i])
                delete materias[i];
            if (obj.materias[i])
                materias[i] = obj.materias[i];
            else 
                materias[i] = NULL;
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria* m){

    if (!m)
        return;
    for (size_t i = 0; i < 4; i++)
    {
        if (!materias[i])
        {
            materias[i] = m->clone();
            return ;
        }
    }
    // delte m;
}

AMateria* MateriaSource::createMateria(std::string const &type){

    for (size_t i = 0; i < 4; i++)
    {
        if (materias[i] && materias[i]->getType() == type)
            return (materias[i]->clone());
    }
    return (NULL);
}

MateriaSource::~MateriaSource(){
    for (size_t i = 0; i < 4; i++){
        if (materias[i]){
            delete materias[i];
        }
    }
}