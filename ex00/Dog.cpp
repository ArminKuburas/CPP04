/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:13:47 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/11 15:18:37 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << "\033[1;33mDefault Dog has been created!\033[0m" << std::endl;
}

Dog::Dog(const Dog& source) : Animal(source)
{
	this->_type = source._type;
	std::cout << "\033[1;33mDog has been copied!\033[0m" << std::endl;
}

Dog::~Dog()
{
	std::cout << "\033[1;33mDog has been destroyed!\033[0m" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		std::cout << "\033[1;33mDog is now " << other._type << "\033[0m" << std::endl;
		this->_type = other._type;
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "\033[1;33mDog barks\033[0m" << std::endl;
}