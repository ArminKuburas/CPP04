/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:27:28 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/11 15:31:55 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "\033[1;31mDefault WrongAnimal has been created!\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& source) : _type(source._type)
{
	std::cout << "\033[1;31mWrongAnimal has been copied!\033[0m" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\033[1;31mWrongAnimal has been destroyed!\033[0m" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		std::cout << "\033[1;31mWrongAnimal is now " << other._type << "\033[0m" << std::endl;
		this->_type = other._type;
	}
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "\033[1;31mWrongAnimal makes a sound\033[0m" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return this->_type;
}