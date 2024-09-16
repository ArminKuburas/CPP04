/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtuality_test.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:37:03 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/16 10:02:04 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class base
{
	public:
		virtual ~base()
		{
			std::cout << "Base destructor" << std::endl;
		}
		virtual void member_function()
		{
			std::cout << "Base member function" << std::endl;
		}

};

class derived : public base
{
	public:
		~derived()
		{
			std::cout << "Derived destructor" << std::endl;
		}
		void member_function()
		{
			std::cout << "Derived member function" << std::endl;
		}
};

class derived2 : public derived
{
	public:
		~derived2()
		{
			std::cout << "Derived2 destructor" << std::endl;
		}
};

class derived3 : public base
{
	public:
		~derived3()
		{
			std::cout << "Derived3 destructor" << std::endl;
		}
};

int main()
{
	base *b = new derived;
	b->member_function();
	b->base::member_function();
	delete b;
	std::cout << "---------------------" << std::endl;
	base *c = new derived2;
	delete c;
	std::cout << "---------------------" << std::endl;
	derived *d = new derived2;
	delete d;
	return (0);
	std::cout << "---------------------" << std::endl;
}