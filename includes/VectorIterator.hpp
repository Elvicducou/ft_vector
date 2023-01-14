/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:30:50 by vducoulo          #+#    #+#             */
/*   Updated: 2023/01/14 16:52:31 by vducoulo         ###   ########.fr       */
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

		template <typename O>
		bool operator==(vectorIterator<O> const &rhs)
		{	return (_p == rhs._p);							}

		template <typename O>
		bool operator!=(vectorIterator<O> const &rhs)
		{	return (_p != rhs._p);							}

		template <typename O>
		bool operator>=(vectorIterator<O> const &rhs)
		{	return (_p >= rhs._p);							}
		
		template <typename O>
		bool operator<=(vectorIterator<O> const &rhs)
		{	return (_p <= rhs._p);							}
		
		template <typename O>
		bool operator<(vectorIterator<O> const &rhs)
		{	return (_p < rhs._p);							}
		
		template <typename O>
		bool operator>(vectorIterator<O> const &rhs)
		{	return (_p > rhs._p);							}

		vectorIterator operator+(difference_type const n) const
		{
			vectorIterator tmp(_p);
			tmp += n;
			return (tmp);							
		}

		vectorIterator operator-(difference_type const n) const
		{
			vectorIterator tmp(_p);
			tmp -= n;
			return (tmp);							
		}

		vectorIterator &operator+=(int increment)
		{	return (_p += increment, *this);				}

		vectorIterator &operator-=(int increment)
		{	return (_p -= increment, *this);				}

		vectorIterator &operator++(void)
		{	return (++_p, *this);							}

		vectorIterator &operator--(void)
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

		vectorIterator operator+(const difference_type n) const
		{
			vectorIterator tmp(*this);
			tmp += n;
			return (tmp);
		}

		vectorIterator operator+(const difference_type n) const
		{
			vectorIterator tmp(*this);
			tmp += n;
			return (tmp);
		}

		reference operator[](int index)
		{ 	return _p[index];								}

		reference operator[](int index) const
		{ 	return _p[index];								}

		pointer base(void) const
		{	return (_p);									}

		friend vectorIterator operator-(difference_type n, vectorIterator &rhs)
		{
			vectorIterator tmp(rhs);
			tmp -= n;
			return (tmp);
		}

		friend vectorIterator operator+(difference_type n, vectorIterator &rhs)
		{
			vectorIterator tmp(rhs);
			tmp += n;
			return (tmp);
		}

		friend difference_type	operator-(const vectorIterator& lhs, const vectorIterator& rhs)
		{	return (lhs._ptr - rhs._ptr);					}

		friend difference_type	operator+(const vectorIterator& lhs, const vectorIterator& rhs)
		{	return (lhs._ptr + rhs._ptr);					}
	};
}
#endif