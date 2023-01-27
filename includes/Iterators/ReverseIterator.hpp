/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:10:26 by vducoulo          #+#    #+#             */
/*   Updated: 2023/01/27 15:46:54 by vducoulo         ###   ########.fr       */
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

		typedef			 Iterator 											iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;

		protected :

		Iterator _i;

		public :
		
		reverse_iterator() : _i(nullptr) {}
		explicit reverse_iterator (iterator_type it) : _i(it) {}
		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it) { _i = rev_it._i; }
		virtual ~reverse_iterator() {};


		//		Member functions			//
		
		iterator_type base() const
		{
			return (_i);
		}

		template <class Iter>
  		reverse_iterator& operator= (const reverse_iterator<Iter>& rev_it)
		{
			_i = rev_it._i;
		}

		reference operator*() const
		{
			return (*(_i - 1));
		}
		
		reverse_iterator operator+ (difference_type n) const
		{
			return (revrse_operator(this - n));
		}

		reverse_iterator& operator++(void)
		{
			return (reverse_iterator(--_i));
		}
		
		reverse_iterator  operator++(int)
		{
			return(--_i, reverse_iterator(_i + 1));
		}
		
		reverse_iterator& operator+= (difference_type n)
		{
			return (_i -= n, this);
		}

		reverse_iterator operator- (difference_type n) const
		{
			return (reverse_iterator(this + n));
		}

		reverse_iterator& operator--(void)
		{
			return (++_i, *this);
		}

		reverse_iterator  operator--(int)
		{
			return (++_i, reverse_iterator(_i - 1));
		}

		reverse_iterator& operator-= (difference_type n)
		{
			_i += n;
			return (this);
		}
		
		pointer operator->() const
		{
			return (&(operator*()));
		}
		
		reference operator[] (difference_type n) const
		{
			return (_i[n]);
		}

		//		End of Members functions		//
		
	};

	template <class Iterator>
  	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}
	
	template <class Iterator>
  	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
  	bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}
	
	template <class Iterator>
  	bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class Iterator>
  	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator>
  	reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{
		return (rev_it + n);
	}

	template <class Iterator>
  	reverse_iterator<Iterator> operator- (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{
		return (rev_it - n);
	}

	template <class Iterator>
  	typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs - rhs);
	}
}

# endif