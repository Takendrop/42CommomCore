/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:18:22 by jwozniak          #+#    #+#             */
/*   Updated: 2024/08/10 20:18:23 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
public:
    PhoneBook();
    ~PhoneBook();
    void addContact();
    void searchContacts() const;
private:
    Contact _contacts[8];
    int _currentIndex;
    int _totalContacts;
    void displayContact(int index) const;
    void displayTable() const;
    std::string truncateString(const std::string& str) const;
};

#endif
