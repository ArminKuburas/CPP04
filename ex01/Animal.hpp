/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:05:19 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/12 22:44:18 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	public:
		Animal();
		Animal(const Animal& source);
		virtual ~Animal();

		Animal& operator=(const Animal& other);

		virtual void makeSound(void) const;
		std::string getType(void) const;
	protected:
		std::string _type;

};

#endif