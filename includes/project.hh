/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.hh                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:29:52 by vducoulo          #+#    #+#             */
/*   Updated: 2023/01/17 15:46:27 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_PROJECT_HH
# define CPP_PROJECT_HH

# include <iostream>
# include <cstddef>
# include <memory>

namespace ft
{
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