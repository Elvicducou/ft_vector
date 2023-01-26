/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorTraits.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:10:21 by vducoulo          #+#    #+#             */
/*   Updated: 2023/01/26 22:51:34 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_ITERATORTRAITS_HPP
# define CPP_ITERATORTRAITS_HPP

# include "../project.hh"

namespace ft {

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct random_access_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public bidirectional_iterator_tag {};
	
	template <class Iterator>
	class iterator_traits
	{
		public :
		
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	class iterator_traits<T*>
	{
		public :

		typedef T 								value_type;
		typedef T 								*pointer;
		typedef T 								&reference;
		typedef	std::ptrdiff_t 					difference_type;
		typedef ft::random_access_iterator_tag	iterator_category;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		public : 
		
		typedef T 								value_type;
		typedef T 								*pointer;
		typedef T 								&reference;
		typedef	std::ptrdiff_t 					difference_type;
		typedef ft::random_access_iterator_tag	iterator_category;
	};
	
} //namespace ft

#endif