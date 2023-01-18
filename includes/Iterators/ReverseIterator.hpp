/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:10:26 by vducoulo          #+#    #+#             */
/*   Updated: 2023/01/18 18:50:46 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_REVERSEITERATOR_HPP
# define CPP_REVERSEITERATOR_HPP
#include "IteratorTraits.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
		public :

		typedef				Iterator											iterator_type;
		typedef	typename	ft::iterator_traits<Iterator>::iterator_category 	iterator_category;
		typedef	typename	ft::iterator_traits<Iterator>::value_type			value_type;
		typedef	typename 	ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef	typename 	ft::iterator_traits<Iterator>::pointer				pointer;
		typedef	typename 	ft::iterator_traits<Iterator>::reference			reference;

		reverse_iterator() {};

		explicit reverse_iterator (iterator_type it);

		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it);

		virtual ~reverse_iterator();
	};
}

# endif