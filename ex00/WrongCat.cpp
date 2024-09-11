/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:28:52 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/11 15:29:56 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "\033[1;31mDefault WrongCat has been created!\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat& source) : WrongAnimal(source)
{
	this->_type = source._type;
	std::cout << "\033[1;31mWrongCat has been copied!\033[0m" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "\033[1;31mWrongCat has been destroyed!\033[0m" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		std::cout << "\033[1;31mWrongCat is now " << other._type << "\033[0m" << std::endl;
		this->_type = other._type;
	}
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "\033[1;31mWrongCat meows\033[0m" << std::endl;
}