/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:19:02 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/16 09:10:55 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		Animal k;
		Dog rex;
		Cat bill;
		
		
		rex.makeSound();
		bill.makeSound();
		std::cout << k.getType() << " " << std::endl;

		delete j;
		delete i;
		delete meta;
		std::cout << "---------------------" << std::endl;
	}
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* j = new WrongCat();

		std::cout << j->getType() << " " << std::endl;
		j->makeSound();
		meta->makeSound();

		WrongAnimal k;
		k = *j;

		WrongCat rex;
		
		rex.makeSound();
		std::cout << k.getType() << " " << std::endl;

		delete j;
		delete meta;
		std::cout << "---------------------" << std::endl;
	}
	{
		std::cout << "---------------------" << std::endl;
		std::cout << "Time to try out all constructors!" << std::endl;	

		Animal a;
		Animal b(a);
		Animal c;
		c = a;
		std::cout << "---------------------" << std::endl;
		Cat d;
		Cat e(d);
		Cat f;
		f = d;
		std::cout << "---------------------" << std::endl;
		Dog g;
		Dog h(g);
		Dog i;
		i = g;
		std::cout << "---------------------" << std::endl;
		WrongAnimal j;
		WrongAnimal k(j);
		WrongAnimal l;
		l = j;
		std::cout << "---------------------" << std::endl;
		WrongCat m;
		WrongCat n(m);
		WrongCat o;
		o = m;
	}
	return (0);
}