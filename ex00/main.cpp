/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:09:38 by coder             #+#    #+#             */
/*   Updated: 2022/02/15 19:09:53 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int	main(void) {

	{
		std::vector<int> vec;
		for (int i = 0; i < 5; i++) {
			vec.push_back(i);
		}
		std::vector<int>::iterator found;
		try {
			found = easyfind(vec, 3);
			std::cout << "found value:" << *found << std::endl;
			found = easyfind(vec, 42);
			std::cout << "found value:" << *found << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::list<int> listI;
		for (int i = 0; i < 5; i++) {
			listI.push_back(i);
		}
		std::list<int>::iterator found;
		try {
			found = easyfind(listI, 4);
			std::cout << "found value:" << *found << std::endl;
			found = easyfind(listI, 5);
			std::cout << "found value:" << *found << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}