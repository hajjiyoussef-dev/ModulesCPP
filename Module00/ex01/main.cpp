


#include "PhoneBook.h"


int main(void){

    PhoneBook pb;

    std::string cmd;

    while( true ){
        std::cout << "enter one of three commands (ADD, SEARCH and EXIT): ";
        if (!std::getline(std::cin, cmd)){
            break;
        }
        if (strcmp(cmd.c_str(), "ADD") == 0){
            pb.addContact();
        }
        else if (strcmp(cmd.c_str(), "SEARCH") == 0){
            pb.searchContacts();
        }
        else if (strcmp(cmd.c_str(), "EXIT") == 0){
            break;
        }
    }
    return (0);
}    