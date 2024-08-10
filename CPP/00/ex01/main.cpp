/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:18:32 by jwozniak          #+#    #+#             */
/*   Updated: 2024/08/10 20:18:33 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main()
{
    PhoneBook phoneBook;
    std::string command;
    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD")
        {
            phoneBook.addContact();
        } else if (command == "SEARCH")
        {
            phoneBook.searchContacts();
        } else if (command == "EXIT")
        {
            break;
        } else
        {
            std::cout << "Invalid command." << std::endl;
        }
    }
    return (0);
}
