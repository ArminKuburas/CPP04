/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 03:55:05 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/16 03:57:47 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_materias[i] = nullptr;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (_materias[i])
			delete _materias[i];
}

MateriaSource::MateriaSource(const MateriaSource& source)
{
	for (int i = 0; i < 4; i++)
		if (source._materias[i])
			_materias[i] = source._materias[i]->clone();
		else
			_materias[i] = nullptr;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i])
			delete _materias[i];
		if (other._materias[i])
			_materias[i] = other._materias[i]->clone();
		else
			_materias[i] = nullptr;
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_materias[i])
		{
			_materias[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i] && _materias[i]->getType() == type)
			return (_materias[i]->clone());
	}
	return (nullptr); //Is nullptr considered 0? If not, return 0
}