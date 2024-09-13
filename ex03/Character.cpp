/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 23:18:18 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/12 23:23:31 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(const Character& source) : _name(source._name)
{
	for (int i = 0; i < 4; i++)
		if (source._inventory[i])
			_inventory[i] = source._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
}

Character& Character::operator=(const Character& other)
{
	if (this == &other)
		return (*this);
	_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
}