/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:30:50 by vducoulo          #+#    #+#             */
/*   Updated: 2023/01/13 22:42:55 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CPP_VECTORITERATOR_HPP
#define CPP_VECTORITERATOR_HPP

#include "project.hh"
	
namespace ft
{
	template <typename T>
	class vectorIterator
	{
		public : 

		typedef T 		value_type;
		typedef T 		*pointer;
		typedef T const *pointer_const;
		typedef T 		&reference;
		typedef T const &reference_const;
		typedef	std::ptrdiff_t difference_type;
		
		protected :

		pointer _p;
		
		public : 

						vectorIterator()							: _p(nullptr) 	{};
						vectorIterator(vectorIterator const &base) 	: _p(base._p) 	{};
						vectorIterator(pointer base)				: _p(base)		{};
		virtual 		~vectorIterator() 											{};
		
		
		vectorIterator	&operator=(vectorIterator const &rhs)
		{	return (this->_p = rhs._p, *this);				}
		
		reference 		operator*(void) const
		{	return (*this->_p);								}

		pointer			operator->() const
		{	return (&(operator*()));						}

		bool operator==(vectorIterator const &rhs)
		{	return (_p == rhs._p);							} // better with friend ?

		bool operator!=(vectorIterator const &rhs)
		{	return (_p != rhs._p);							} // better with friend ?

		bool operator>=(vectorIterator const &rhs)
		{	return (_p >= rhs._p);							} // better with friend ?

		bool operator<=(vectorIterator const &rhs)
		{	return (_p <= rhs._p);							} // better with friend ?

		bool operator<(vectorIterator const &rhs)
		{	return (_p < rhs._p);							} // better with friend ?

		bool operator>(vectorIterator const &rhs)
		{	return (_p > rhs._p);							} // better with friend ?

		bool operator+(vectorIterator const &rhs)
		{	return (_p + rhs._p);							} //not_sure

		bool operator-(vectorIterator const &rhs)
		{	return (_p - rhs._p);							} //not_sure

		vectorIterator &operator+=(int increment)
		{	return (_p += increment, *this);				}

		vectorIterator &operator-=(int increment)
		{	return (_p -= increment, *this);				}

		vectorIterator &operator++()
		{	return (++_p, *this);							}

		vectorIterator &operator--()
		{	return (--_p, *this);							}
		
		vectorIterator operator++(int)
		{	
			vectorIterator<T> tmp(*this);
			return (++_p, tmp);
		}

		vectorIterator operator--(int)
		{	
			vectorIterator<T> tmp(*this);
			return (--_p, tmp);
		}
	};
}
#endif