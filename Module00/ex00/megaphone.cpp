/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajji <yhajji@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-12 21:51:30 by yhajji            #+#    #+#             */
/*   Updated: 2025-08-12 21:51:30 by yhajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    if (argc > 1){

       for (int i = 1; argv[i]; i++){
        for (int j = 0; argv[i][j] != '\0'; j++){
            if (isalpha(argv[i][j]) && tolower(argv[i][j]))
                std::cout << (char)toupper(argv[i][j]);
            else 
                std::cout << argv[i][j];
        }
       }
       std::cout << std::endl;
    }
    else 
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}
