/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:19:02 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/16 12:08:39 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	int amount;

	amount = 4;
	Animal** array_of_animals = new Animal*[amount];

	for (int i = 0; i < amount; i++)
	{
		if (i % 2 == 0)
			array_of_animals[i] = new Dog();
		else
			array_of_animals[i] = new Cat();
	}
	for (int i = 0; i < amount; i++)
	{
		array_of_animals[i]->makeSound();
		std::cout << array_of_animals[i]->getType() << std::endl;
		delete array_of_animals[i];
		std::cout << "---------------------" << std::endl;
	}
	delete[] array_of_animals;
	std::cout << "---------------------" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
	std::cout << "---------------------" << std::endl;
	return (0);
}