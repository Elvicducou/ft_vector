/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:30:50 by vducoulo          #+#    #+#             */
/*   Updated: 2022/12/29 16:33:21 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CPP_VECTORITERATOR_HPP
#define CPP_VECTORITERATOR_HPP

#include "project.hh"

namespace ft
{
	template <typename T>
	class VectorIterator
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
		
		
		VectorIterator	&operator=(VectorIterator const &rhs)
		{	return (this->_p = rhs._p, *this);				}
		
		reference 		operator*(void)
		{	return (*this->_p);									}


	};
}
#endif