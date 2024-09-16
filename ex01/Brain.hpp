/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:56:04 by akuburas          #+#    #+#             */
/*   Updated: 2024/09/16 13:53:16 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	public:
		Brain();
		Brain(const Brain& source);
		~Brain();

		Brain& operator=(const Brain& other);
		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;
	private:
		std::string _ideas[100];
};


#endif