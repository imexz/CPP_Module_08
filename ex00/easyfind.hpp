/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:09:41 by coder             #+#    #+#             */
/*   Updated: 2022/02/15 19:09:51 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <algorithm>

class NotFound : public std::exception {

	public:

		char const	*what(void) const throw() {
			return "Not Found Exception thrown";
		}
};

template <typename T>
typename T::iterator	easyfind(T &container, int value) {

	typename T::iterator	it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFound();
	return (it);
}

#endif
