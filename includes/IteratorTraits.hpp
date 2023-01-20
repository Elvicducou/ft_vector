/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorTraits.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:10:21 by vducoulo          #+#    #+#             */
/*   Updated: 2023/01/20 17:33:57 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_ITERATORTRAITS_HPP
# define CPP_ITERATORTRAITS_HPP

# include "project.hh"

namespace ft {

	template <class Iterator> //add iterator category ?
	class iterator_traits
	{
		public :
		
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};

	template <class T>
	class iterator_traits<T*>
	{
		public :

		typedef T 				value_type;
		typedef T 				*pointer;
		typedef T 				&reference;
		typedef	std::ptrdiff_t 	difference_type;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		public : 
		
		typedef T 				value_type;
		typedef T 				*pointer;
		typedef T 				&reference;
		typedef	std::ptrdiff_t 	difference_type;
	};
	
} //namespace ft

#endif