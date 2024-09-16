/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 04:33:23 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/16 13:39:53 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main(void)
{
	{
		std::cout << "-------- Test 1: Basic Creation and Use --------" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		AMateria* tmp;

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");
		me->use(0, *bob); // ice
		me->use(1, *bob); // cure

		delete bob;
		delete me;
		delete src;
	}
	std::cout << "-----------------------------------" << std::endl;
	{
		std::cout << "-------- Test 2: Equip and Unequip --------" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* alice = new Character("alice");
		AMateria* tmp1 = src->createMateria("ice");
		AMateria* tmp2 = src->createMateria("cure");

		alice->equip(tmp1);
		alice->equip(tmp2);

		std::cout << "Equipping two Materia..." << std::endl;

		alice->unequip(0);
		std::cout << "Unequipped slot 0 (ice)" << std::endl;
		alice->use(0, *alice);

		alice->equip(tmp1);
		std::cout << "Re-equipping slot 0 with ice" << std::endl;
		alice->use(0, *alice);

		delete alice;
		delete src;
		//delete tmp1;
		//delete tmp2;
	}
	std::cout << "-----------------------------------" << std::endl;
	{
		std::cout << "-------- Test 3: Inventory Overflow --------" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* john = new Character("john");
		AMateria* m1 = src->createMateria("ice");
		AMateria* m2 = src->createMateria("cure");
		AMateria* m3 = src->createMateria("ice");
		AMateria* m4 = src->createMateria("cure");
		AMateria* m5 = src->createMateria("ice"); // This one should not fit

		john->equip(m1);
		john->equip(m2);
		john->equip(m3);
		john->equip(m4);

		std::cout << "Trying to equip 5th Materia into a 4-slot inventory..." << std::endl;
		john->equip(m5); // Shouldn't equip

		john->use(0, *john); // ice
		john->use(1, *john); // cure
		john->use(2, *john); // ice
		john->use(3, *john); // cure

		delete john;
		delete src;
		// delete m1;
		// delete m2;
		// delete m3;
		// delete m4;
		delete m5;
	}
	std::cout << "-----------------------------------" << std::endl;
	{
		std::cout << "-------- Test 4: Deep Copy --------" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		Character *character_alice = new Character("alice");
		ICharacter* alice = character_alice;
		alice->equip(src->createMateria("ice"));
		alice->equip(src->createMateria("cure"));

		std::cout << "Creating a deep copy of character 'alice' to 'cloneAlice'..." << std::endl;
		Character *cloneAlice(character_alice);

		cloneAlice->use(0, *cloneAlice); // Should output ice
		cloneAlice->use(1, *cloneAlice); // Should output cure

		delete alice;
		// delete cloneAlice;
		delete src;
	}
	std::cout << "-----------------------------------" << std::endl;
	{
		std::cout << "-------- Test 5: Memory Leaks Check --------" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* testCharacter = new Character("tester");
		AMateria* temp;

		for (int i = 0; i < 4; i++) {
			temp = src->createMateria(i % 2 == 0 ? "ice" : "cure");
			testCharacter->equip(temp);
		}

		for (int i = 0; i < 4; i++) {
			testCharacter->use(i, *testCharacter);
		}

		delete testCharacter;
		delete src;
	}
	std::cout << "-----------------------------------" << std::endl;
	{
		std::cout << "-------- Test 6: Invalid Materia Handling --------" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* jack = new Character("jack");
		AMateria* tmp;

		tmp = src->createMateria("fire"); // Unknown type
		if (tmp == nullptr)
			std::cout << "Cannot create 'fire' Materia, type unknown!" << std::endl;

		delete jack;
		delete src;
	}
	std::cout << "-----------------------------------" << std::endl;
	{
		    std::cout << "-------- Test 7: Learning More Than 4 Materias --------" << std::endl;

    IMateriaSource* src = new MateriaSource();
    AMateria* m1 = new Cure();
    AMateria* m2 = new Cure();
    AMateria* m3 = new Cure();
    AMateria* m4 = new Cure();
    AMateria* m5 = new Ice(); // This will be the fifth one we attempt to learn

    src->learnMateria(m1); // Should succeed
    src->learnMateria(m2); // Should succeed
    src->learnMateria(m3); // Should succeed
    src->learnMateria(m4); // Should succeed
    src->learnMateria(m5); // Should NOT succeed, MateriaSource only holds 4 Materias

    AMateria* tmp = src->createMateria("ice");

    if (tmp == nullptr) {
        std::cout << "Could not learn the fifth materia (ice). MateriaSource is full." << std::endl;
    } else {
        std::cout << "Fifth materia was incorrectly learned." << std::endl;
    }

    delete m5; // We held onto m5, so we delete it manually
    delete src;
	}
	return (0);
}