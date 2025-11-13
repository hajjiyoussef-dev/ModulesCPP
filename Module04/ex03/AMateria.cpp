#include "AMateria.hpp"



AMateria::AMateria() : type("default") {}

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::AMateria(const AMateria &obj){

    *this = obj;
}

AMateria &AMateria::operator=(const AMateria &obj){

    if (this != &obj)
        type = obj.type;
    return (*this);
}

std::string const &AMateria::getType( void ) const {

    return (type);
}

AMateria::~AMateria() {}

void AMateria::use(ICharacter& target){

    std::cout << "* generic materia used on " << target.getName() << " *" << std::endl;

}