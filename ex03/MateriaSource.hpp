/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 03:53:00 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/16 03:54:58 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		virtual ~MateriaSource();
		MateriaSource(const MateriaSource& source);
		
		MateriaSource& operator=(const MateriaSource& other);

		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
	private:
		AMateria* _materias[4];
};

#endif