/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:30:50 by vducoulo          #+#    #+#             */
/*   Updated: 2023/01/10 18:22:04 by vducoulo         ###   ########.fr       */
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

						VectorIterator()							: _p(nullptr) 	{};
						VectorIterator(VectorIterator const &base) 	: _p(base._p) 	{};
						VectorIterator(pointer base)				: _p(base)		{};
		virtual 		~VectorIterator() 											{};
		
		
		vectorIterator	&operator=(VectorIterator const &rhs)
		{	return (this->_p = rhs._p, *this);				}
		
		reference 		operator*(void) const
		{	return (*this->_p);								}

		pointer			operator->()
		{	return (this->_p);								}

		bool operator==(VectorIterator const &rhs)
		{	return (_p == rhs._p);							} // better with friend ?

		bool operator!=(VectorIterator const &rhs)
		{	return (_p != rhs._p);							} // better with friend ?

		bool operator>=(VectorIterator const &rhs)
		{	return (_p >= rhs._p);							} // better with friend ?

		bool operator<=(VectorIterator const &rhs)
		{	return (_p <= rhs._p);							} // better with friend ?

		bool operator<(VectorIterator const &rhs)
		{	return (_p < rhs._p);							} // better with friend ?

		bool operator>(VectorIterator const &rhs)
		{	return (_p > rhs._p);							} // better with friend ?

		bool operator+(VectorIterator const &rhs)
		{	return (_p + rhs._p);							} //not_sure

		bool operator-(VectorIterator const &rhs)
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
			VectorIterator<T> tmp(*this);
			return (++_p, tmp);
		}

		vectorIterator operator--(int)
		{	
			VectorIterator<T> tmp(*this);
			return (--_p, tmp);
		}
	};
}
#endif