#pragma once 

#include <iostream> 

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &obj);
        WrongAnimal &operator=(const WrongAnimal &obj);
        ~WrongAnimal();

        void makeSound() const;
        std::string getType() const;
};

