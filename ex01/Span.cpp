/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:22:12 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/16 20:18:29 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>

Span::Span(void) {

}

Span::Span(Span const &src) {

	_N = src._N;
	_currPos = src._currPos;
	_v = src._v;
}

Span::Span(unsigned int N) : _N(N), _currPos(0) {

}

Span::~Span(void) {

}

Span	&Span::operator=(Span const &src) {

	if (this != &src) {
		_N = src._N;
		_currPos = src._currPos;
		_v = src._v;
	}
	return (*this);
}

void	Span::addNumber(int num) {

	if (_currPos >= _N) {
		throw FullStorageException();
	}
	_v.push_back(num);
	_currPos++;
}

int	Span::shortestSpan(void) {

	int	shortestSpan;
	std::vector<int> tmp;

	if (_currPos <= 1) {
		throw NoSpanException();
	}
	tmp = _v;
	shortestSpan = INT_MAX;
	sort(tmp.begin(), tmp.end());
	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++) {
		if (it + 1 != tmp.end() && *(it + 1) - *it < shortestSpan) {
			shortestSpan = *(it + 1) - *it;
		}
	}
	return (shortestSpan);
}

int	Span::longestSpan(void) {

	std::vector<int>::iterator	min;
	std::vector<int>::iterator	max;

	if (_currPos <= 1)
		throw NoSpanException();
	min = min_element(_v.begin(), _v.end());
	max = max_element(_v.begin(), _v.end());
	return (*max - *min);

}

void	Span::fillSpan(std::vector<int>::iterator start, std::vector<int>::iterator end) {

	unsigned int size = std::distance(start, end);
	unsigned int availableSlots = _N - _currPos;

	if (size > availableSlots) {
		_v.insert(_v.end(), start, end - (size - availableSlots));
		_currPos += availableSlots;
	}
	else {
		_v.insert(_v.end(), start, end);
		_currPos += size;
	}
}

std::vector<int>	&Span::getV(void) {

	return (_v);
}
