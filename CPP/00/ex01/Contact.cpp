/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:17:09 by jwozniak          #+#    #+#             */
/*   Updated: 2024/08/10 20:17:10 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void Contact::setFirstName(const std::string& firstName)
{
    _firstName = firstName;
}

void Contact::setLastName(const std::string& lastName)
{
    _lastName = lastName;
}

void Contact::setNickname(const std::string& nickname)
{
    _nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber)
{
    _phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret)
{
    _darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const
{
    return (_firstName);
}

std::string Contact::getLastName() const
{
    return (_lastName);
}

std::string Contact::getNickname() const
{
    return (_nickname);
}

std::string Contact::getPhoneNumber() const
{
    return (_phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
    return (_darkestSecret);
}
