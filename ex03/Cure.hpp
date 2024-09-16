/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 03:45:16 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/16 03:47:16 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	Cure();
	virtual ~Cure();
	Cure(const Cure& source);
	
	Cure& operator=(const Cure& other);

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif