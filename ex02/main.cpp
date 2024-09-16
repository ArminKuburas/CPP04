/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:19:02 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/16 13:07:39 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Dog j;
	//const Animal i;

	const Animal* x = new Dog;
	std::cout << x->getType() << " " << std::endl;
	std::cout << j.getType() << " " << std::endl;
	delete x;
	return (0);
}