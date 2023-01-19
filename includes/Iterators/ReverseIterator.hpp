/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:10:26 by vducoulo          #+#    #+#             */
/*   Updated: 2023/01/19 12:58:33 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_REVERSEITERATOR_HPP
# define CPP_REVERSEITERATOR_HPP

#include "IteratorTraits.hpp"
#include "../project.hh"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
		public :

		typedef				Iterator											iterator_type;
		typedef	typename	ft::iterator_traits<Iterator>::value_type			value_type;
		typedef	typename 	ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef	typename 	ft::iterator_traits<Iterator>::pointer				pointer;
		typedef	typename 	ft::iterator_traits<Iterator>::reference			reference;

		protected :

		Iterator _i;

		public :
		
		reverse_iterator() : _i(nullptr) {}
		explicit reverse_iterator (iterator_type it) : _i(it) {}
		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it) { _i = rev_it._i; }
		virtual ~reverse_iterator() {};

		iterator_type base() const;
		reference operator*() const;
		reverse_iterator operator+ (difference_type n) const;
		reverse_iterator& operator++();
		reverse_iterator  operator++(int);
		reverse_iterator& operator+= (difference_type n);
		reverse_iterator operator- (difference_type n) const;
		reverse_iterator& operator--();reverse_iterator  operator--(int);
		reverse_iterator& operator-= (difference_type n);
		pointer operator->() const;
		reference operator[] (difference_type n) const;
	};
}

# endif