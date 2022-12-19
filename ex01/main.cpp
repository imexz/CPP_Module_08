/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:22:09 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/16 20:20:39 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

void	print(int i) {
	std::cout << " " << i;
}

int main(void)
{
	std::cout << "Simple test:" << std::endl;

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl;

	std::cout << "Exceptions:" << std::endl;

	try {

		Span sp2 = Span(3);

		sp2.addNumber(5);
		sp2.addNumber(3);
		sp2.addNumber(17);
		sp2.addNumber(9);		//Exception: "Full Storage Exception thrown"
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Span sp3 = Span(1);

		sp3.longestSpan();		//Exception: "No span can be found" -> no numbers stored yet
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Span sp3 = Span(1);
		sp3.shortestSpan();		//Exception: "No span can be found" -> no numbers stored yet
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Span sp3 = Span(1);
		sp3.addNumber(5);
		sp3.shortestSpan();		//Exception: "No span can be found" -> just one number stored
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Span sp3 = Span(1);
		sp3.addNumber(5);
		sp3.longestSpan();		//Exception: "No span to find" -> just one number stored
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

/* -------------------------------------------------------------------------- */

	std::cout << "Add numbers by passing range of iterators:" << std::endl;

	Span sp4 = Span(20001);

	std::vector<int> vector;
	for (int i = 0; i < 20001; i++)
		vector.push_back(i);

	sp4.fillSpan(vector.begin(), vector.end());

	std::cout << sp4.shortestSpan() << std::endl;
	std::cout << sp4.longestSpan() << std::endl;

	try {
		Span sp5 = Span(100);
		std::vector<int> vector;
		for (int i = 0; i < 100; i++)
			vector.push_back(i);
		for (int i = 0; i < 50; i++)
			sp5.addNumber(42);
		sp5.fillSpan(vector.begin(), vector.end());
		std::vector<int> v = sp5.getV();
		for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
			std::cout << "  " << *it;
		}
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}