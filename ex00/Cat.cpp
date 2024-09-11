/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:18:59 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/11 15:20:40 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << "\033[1;35mDefault Cat has been created!\033[0m" << std::endl;
}

Cat::Cat(const Cat& source) : Animal(source)
{
	this->_type = source._type;
	std::cout << "\033[1;35mCat has been copied!\033[0m" << std::endl;
}

Cat::~Cat()
{
	std::cout << "\033[1;35mCat has been destroyed!\033[0m" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		std::cout << "\033[1;35mCat is now " << other._type << "\033[0m" << std::endl;
		this->_type = other._type;
	}
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "\033[1;35mCat meows\033[0m" << std::endl;
}