/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:13:47 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/16 13:52:14 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "\033[1;33mDefault Dog has been created!\033[0m" << std::endl;
}

Dog::Dog(const Dog& source) : Animal(source)
{
	this->_type = source._type;
	this->_brain = new Brain(*source._brain);
	std::cout << "\033[1;33mDog has been copied!\033[0m" << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "\033[1;33mDog has been destroyed!\033[0m" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		std::cout << "\033[1;33mDog is now " << other._type << "\033[0m" << std::endl;
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
		this->_type = other._type;
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "\033[1;33mDog barks\033[0m" << std::endl;
}

Brain* Dog::getBrain(void) const
{
	return (this->_brain);
}