#pragma once 


#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    // private:
    //     std::string* idea;
    public:
        WrongCat();
        WrongCat(const WrongCat &obj);
        WrongCat &operator=(const WrongCat &obj);
        ~WrongCat();
        void makeSound() const;
};


