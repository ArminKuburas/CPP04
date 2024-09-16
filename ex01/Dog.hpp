/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:12:12 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/16 13:47:48 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& source);
		virtual ~Dog();

		Dog& operator=(const Dog& other);
		
		void makeSound(void) const;
		Brain * getBrain(void) const;
	private:
		Brain *_brain;
};

#endif