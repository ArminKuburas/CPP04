/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:59:16 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/16 13:54:44 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "\033[1;33mBrain has been created!\033[0m" << std::endl;
	int i = 0;
	while (i < 100)
	{
		this->_ideas[i] = "Empty";
		i++;
	}
}

Brain::Brain(const Brain& source)
{
	std::cout << "\033[1;33mBrain has been copied!\033[0m" << std::endl;
	int i = 0;
	while (i < 100)
	{
		this->_ideas[i] = source._ideas[i];
		i++;
	}
}

Brain::~Brain()
{
	std::cout << "\033[1;33mBrain has been destroyed!\033[0m" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		std::cout << "\033[1;33mBrain has been assigned!\033[0m" << std::endl;
		int i = 0;
		while (i < 100)
		{
			this->_ideas[i] = other._ideas[i];
			i++;
		}
	}
	return (*this);
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
	{
		return "Invalid idea index!";
	}
	return this->_ideas[index];
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100) {
		this->_ideas[index] = idea;
	}
	else
	{
		std::cout << "Invalid idea index!" << std::endl;
	}
}
