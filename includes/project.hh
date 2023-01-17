/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.hh                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:29:52 by vducoulo          #+#    #+#             */
/*   Updated: 2023/01/17 17:56:36 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_PROJECT_HH
# define CPP_PROJECT_HH

# include <iostream>
# include <cstddef>
# include <memory>

namespace ft
{
	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return (false);
			first1++, first2++;
		}
		return (true);
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1 && first2 != last2 && *first1 == *first2)
			first1++, first2++;
		if (first1 == last1 && first2 != last2)
			return (true);
		else if (first1 != last1 && first2 == last2)
			return (false);
		else
			return (*first1 < *first2);
	}

	template< bool B, class True = void >
	struct enable_if;

	template<class True>
	struct enable_if<true, True>
	{
		typedef True istrue;
	};
	
	template <class data_type>
	void exchange(data_type &a, data_type &b)
	{
		data_type tmp(a);
		a = b;
		b = tmp;
	}

	template <class ite>
	size_t iterator_diff(ite first, ite last)
	{
		size_t i = 0;
		while (first != last)
			i++, first++;
		return (i);
	}
}
#endif