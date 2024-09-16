/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:19:02 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/16 13:56:47 by akuburas         ###   ########.fr       */
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
	std::cout << "-------- Test: Deep Copy of Dog --------" << std::endl;
	Dog* dog1 = new Dog();
	dog1->getBrain()->setIdea(0, "Chase the ball");
	dog1->getBrain()->setIdea(1, "Bark at the mailman");

	Dog* dog2 = new Dog(*dog1);
	std::cout << "Dog 1's idea[0]: " << dog1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog 2's idea[0]: " << dog2->getBrain()->getIdea(0) << std::endl;

	dog2->getBrain()->setIdea(0, "Sleep in the sun");
	std::cout << "After changing Dog 2's idea[0]:" << std::endl;
	std::cout << "Dog 1's idea[0]: " << dog1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog 2's idea[0]: " << dog2->getBrain()->getIdea(0) << std::endl;

	delete dog1;
	delete dog2;

	std::cout << "-------- Test: Deep Copy of Cat --------" << std::endl;
	Cat* cat1 = new Cat();
	cat1->getBrain()->setIdea(0, "Chase a mouse");
	cat1->getBrain()->setIdea(1, "Climb the curtains");

	Cat* cat2 = new Cat(*cat1);
	std::cout << "Cat 1's idea[0]: " << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat 2's idea[0]: " << cat2->getBrain()->getIdea(0) << std::endl;

	cat2->getBrain()->setIdea(0, "Take a nap");
	std::cout << "After changing Cat 2's idea[0]:" << std::endl;
	std::cout << "Cat 1's idea[0]: " << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat 2's idea[0]: " << cat2->getBrain()->getIdea(0) << std::endl;

	delete cat1;
	delete cat2;

	std::cout << "-------- Test: Assignment Operator Deep Copy --------" << std::endl;
	Dog* dog3 = new Dog();
	Dog* dog4 = new Dog();
	dog3->getBrain()->setIdea(0, "Fetch the stick");
	*dog4 = *dog3;

	std::cout << "Dog 3's idea[0]: " << dog3->getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog 4's idea[0]: " << dog4->getBrain()->getIdea(0) << std::endl;

	dog4->getBrain()->setIdea(0, "Dig a hole");
	std::cout << "After changing Dog 4's idea[0]:" << std::endl;
	std::cout << "Dog 3's idea[0]: " << dog3->getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog 4's idea[0]: " << dog4->getBrain()->getIdea(0) << std::endl;

	delete dog3;
	delete dog4;
	return (0);
}