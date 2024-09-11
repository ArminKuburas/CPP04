/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:19:02 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/11 19:23:31 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	Animal** array_of_animals = new Animal*[4];

	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			array_of_animals[i] = new Dog();
		else
			array_of_animals[i] = new Cat();
	}
	for (int i = 0; i < 4; i++)
	{
		array_of_animals[i]->makeSound();
		std::cout << array_of_animals[i]->getType() << std::endl;
		delete array_of_animals[i];
		std::cout << "---------------------" << std::endl;
	}
	delete[] array_of_animals;
	return (0);
}