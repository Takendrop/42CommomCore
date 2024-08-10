/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:18:27 by jwozniak          #+#    #+#             */
/*   Updated: 2024/08/10 20:18:27 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : _currentIndex(0), _totalContacts(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::addContact() {
    Contact newContact;
    std::string input;
    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    if (input.empty()) return;
    newContact.setFirstName(input);
    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    if (input.empty()) return;
    newContact.setLastName(input);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    if (input.empty()) return;
    newContact.setNickname(input);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    if (input.empty()) return;
    newContact.setPhoneNumber(input);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    if (input.empty()) return;
    newContact.setDarkestSecret(input);
    _contacts[_currentIndex] = newContact;
    _currentIndex = (_currentIndex + 1) % 8;
    if (_totalContacts < 8) _totalContacts++;
}

void PhoneBook::searchContacts() const
{
    displayTable();

    int index;
    std::cout << "Enter index to display: ";
    std::cin >> index;
    std::cin.ignore();

    if (index < 0 || index >= _totalContacts) {
        std::cout << "Invalid index." << std::endl;
        return ;
    }
    displayContact(index);
}

void PhoneBook::displayTable() const
{
    std::cout << std::setw(10) << "Index" << '|'
              << std::setw(10) << "First Name" << '|'
              << std::setw(10) << "Last Name" << '|'
              << std::setw(10) << "Nickname" << '|'
              << std::endl;

    for (int i = 0; i < _totalContacts; ++i)
    {
        std::cout << std::setw(10) << i << '|'
                  << std::setw(10) << truncateString(_contacts[i].getFirstName()) << '|'
                  << std::setw(10) << truncateString(_contacts[i].getLastName()) << '|'
                  << std::setw(10) << truncateString(_contacts[i].getNickname()) << '|'
                  << std::endl;
    }
}

void PhoneBook::displayContact(int index) const
{
    const Contact& contact = _contacts[index];
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

std::string PhoneBook::truncateString(const std::string& str) const
{
    if (str.length() > 10) {
        return (str.substr(0, 9) + '.');
    }
    return (str);
}
