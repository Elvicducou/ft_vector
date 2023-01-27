/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:26:39 by vducoulo          #+#    #+#             */
/*   Updated: 2023/01/27 18:22:21 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_RANDOMACCESSITERATOR_HPP
# define CPP_RANDOMACCESSITERATOR_HPP

#include "../project.hh"

namespace ft
{
	template <class T>
	class random_access_iterator : public iterator<ft::random_access_iterator_tag, T>
	{
		public : 

		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type 		value_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer 			pointer;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference  		reference;
		typedef	typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type 	difference_type;
		typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category iterator_category;
		
		protected : 
		
		pointer _p;

		public : 

						random_access_iterator()									: _p(nullptr) 	{};
						random_access_iterator(random_access_iterator const &base) 	: _p(base._p) 	{};
						random_access_iterator(pointer base)						: _p(base)		{};
						template <class O>
						random_access_iterator(random_access_iterator<O> const &rait)     				{_p = rait.base();}
		virtual 		~random_access_iterator() 													{};
		
		
		random_access_iterator	&operator=(random_access_iterator const &rhs)
		{	return (this->_p = rhs._p, *this);				}
		
		reference 		operator*(void) const
		{	return (*this->_p);								}

		pointer			operator->() const
		{	return (&(operator*()));						}

		friend bool operator==(random_access_iterator<T> const &lhs, random_access_iterator<T> const &rhs)
		{	return (lhs.base() == rhs.base());							}
		
		template <typename O>
		friend bool operator==(random_access_iterator<T> const &lhs, random_access_iterator<O> const &rhs)
		{	return (lhs.base() == rhs.base());						}

		friend bool operator!=(random_access_iterator<T> const &lhs, random_access_iterator<T> const &rhs)
		{	return (lhs.base() != rhs.base());							}
		
		template <typename O>
		friend bool operator!=(random_access_iterator<T> const &lhs, random_access_iterator<O> const &rhs)
		{	return (lhs.base() != rhs.base());						}

		friend bool operator>=(random_access_iterator<T> const &lhs, random_access_iterator<T> const &rhs)
		{	return (lhs.base() >= rhs.base());							}

		template <typename O>
		friend bool operator>=(random_access_iterator<T> const &lhs, random_access_iterator<O> const &rhs)
		{	return (lhs.base() >= rhs.base());						}
		
		friend bool operator<=(random_access_iterator<T> const &lhs, random_access_iterator<T> const &rhs)
		{	return (lhs.base() <= rhs.base());							}

		template <typename O>
		friend bool operator<=(random_access_iterator<T> const &lhs, random_access_iterator<O> const &rhs)
		{	return (lhs.base() <= rhs.base());						}
		
		friend bool operator<(random_access_iterator<T> const &lhs, random_access_iterator<T> const &rhs)
		{	return (lhs.base() < rhs.base());							}
		
		template <typename O>
		friend bool operator<(random_access_iterator<T> const &lhs, random_access_iterator<O> const &rhs)
		{	return (lhs.base() < rhs.base());						}
		
		friend bool operator>(random_access_iterator<T> const &lhs, random_access_iterator<T> const &rhs)
		{	return (lhs.base() > rhs.base());							}

		template <typename O>
		friend bool operator>(random_access_iterator<T> const &lhs, random_access_iterator<O> const &rhs)
		{	return (lhs.base() > rhs.base());						}

		random_access_iterator operator+(difference_type const n) const
		{
			random_access_iterator tmp(_p);
			tmp += n;
			return (tmp);							
		}

		random_access_iterator operator-(difference_type const n) const
		{
			random_access_iterator tmp(_p);
			tmp -= n;
			return (tmp);							
		}

		friend random_access_iterator operator+(difference_type const n, random_access_iterator &rhs)
		{
			random_access_iterator tmp = rhs;
			tmp += n;
			return (tmp);							
		}

		friend random_access_iterator operator-(difference_type const n, random_access_iterator &rhs)
		{
			random_access_iterator tmp = rhs;
			tmp -= n;
			return (tmp);							
		}

		difference_type operator+(random_access_iterator const &rhs) const
		{	return (_p + rhs._p);							}

		difference_type operator-(random_access_iterator const &rhs) const
		{	return (_p - rhs._p);							}

		random_access_iterator &operator+=(difference_type increment)
		{	return (_p += increment, *this);				}

		random_access_iterator &operator-=(difference_type increment)
		{	return (_p -= increment, *this);				}

		random_access_iterator &operator++(void)
		{	return (++_p, *this);							}

		random_access_iterator &operator--(void)
		{	return (--_p, *this);							}
		
		random_access_iterator operator++(int)
		{	
			random_access_iterator<T> tmp(*this);
			return (++_p, tmp);
		}

		random_access_iterator operator--(int)
		{	
			random_access_iterator<T> tmp(*this);
			return (--_p, tmp);
		}

		reference operator[](size_t index)
		{ 	return _p[index];								}

		reference operator[](size_t index) const
		{ 	return _p[index];								}

		pointer base(void) const
		{	return (_p);									}		
	};
}

#endif