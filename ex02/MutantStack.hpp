/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:23:57 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/17 12:34:41 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack : public std::stack<T> {

	private:

	public:

		MutantStack(void) : std::stack<T> (){};
		MutantStack(MutantStack const &src) : std::stack<T>(src) {*this = src;};
		~MutantStack(void) {};

		MutantStack	&operator=(MutantStack const &src) {

			if (this != &src)
				std::stack<T>::operator=(src);
			return (*this);
		};

		typedef typename std::stack<T>::container_type::iterator	iterator;

		iterator	begin(void)	{return (this->c.begin());}
		iterator	end(void)	{return (this->c.end());}

};


#endif
