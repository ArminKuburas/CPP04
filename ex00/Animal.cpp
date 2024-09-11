/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:09:21 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/11 15:11:41 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "\033[1;32mDefault Animal has been created!\033[0m" << std::endl;
}

Animal::Animal(const Animal& source) : _type(source._type)
{
	std::cout << "\033[1;32mAnimal has been copied!\033[0m" << std::endl;
}

Animal::~Animal()
{
	std::cout << "\033[1;32mAnimal has been destroyed!\033[0m" << std::endl;
}

std::string Animal::getType() const
{
	return this->_type;
}

void Animal::makeSound(void) const
{
	std::cout << "\033[1;32mAnimal makes a sound\033[0m" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		std::cout << "\033[1;32mAnimal is now " << other._type << "\033[0m" << std::endl;
		this->_type = other._type;
	}
	return (*this);
}