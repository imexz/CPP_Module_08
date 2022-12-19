/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:22:14 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/16 20:20:48 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <exception>

class Span {

	private:

		std::vector<int>	_v;
		unsigned int		_N;
		unsigned int		_currPos;
		Span(void);

	public:

		Span(Span const &src);
		Span(unsigned int N);
		~Span(void);

		Span	&operator=(Span const &src);
		void	addNumber(int num);
		int		shortestSpan(void);
		int		longestSpan(void);
		void	fillSpan(std::vector<int>::iterator start, std::vector<int>::iterator end);
		std::vector<int>	&getV(void);

	class FullStorageException : public std::exception {
		public:
			char const	*what(void) const throw() {
				return "Full Storage Exception thrown";
			}
	};
	class NoSpanException : public std::exception {
		public:
			char const	*what(void) const throw() {
				return "No span can be found";
			}
	};
};

#endif
