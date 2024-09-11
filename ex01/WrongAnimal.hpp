/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:26:21 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/11 15:31:44 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& source);
		virtual ~WrongAnimal();

		WrongAnimal& operator=(const WrongAnimal& other);
		
		void makeSound(void) const;
		std::string getType(void) const;
	protected:
		std::string _type;
};

#endif