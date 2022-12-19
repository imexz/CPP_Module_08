/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:24:00 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/17 12:36:26 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main(void)
{
	MutantStack<int> mstack;

	std::cout << "MutantStack testing:" << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << "value top element: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size of stack: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
	    std::cout << *it << std::endl;
	++it;
	}
	std::cout << std::endl << "Viewing and popping elements from stack s" << std::endl;
	std::stack<int> s(mstack);
	while (!s.empty()) {
		std::cout << s.top() << std::endl;
		s.pop();
	}

	{
		std::cout << std::endl << "Check against list container:" << std::endl;

		std::list<int> l;

		l.push_front(5);
		l.push_front(17);
		std::cout << "value top element: " << l.front() << std::endl;
		l.pop_front();
		std::cout << "size of list: " << l.size() << std::endl;
		l.push_back(3);
		l.push_back(5);
		l.push_back(737);
		std::list<int>::iterator it = l.begin();
		std::list<int>::iterator ite = l.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
	}
	return 0;
}
