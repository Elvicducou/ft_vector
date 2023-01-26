/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:26:39 by vducoulo          #+#    #+#             */
/*   Updated: 2023/01/26 22:36:21 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../project.hh"

namespace ft
{
	template <class T>
	class random_access_iterator : public iterator<ft::random_access_iterator_tag, T>
	{
		public : 

		typedef T 				value_type;
		typedef T 				*pointer;
		typedef T const 		*pointer_const;
		typedef T 				&reference;
		typedef T const 		&reference_const;
		typedef	std::ptrdiff_t	difference_type;
	}
}