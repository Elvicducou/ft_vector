/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:25:12 by vducoulo          #+#    #+#             */
/*   Updated: 2023/01/11 23:51:05 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/Vector.hpp"
# include <vector>
# include <iostream>

void testspace_iterator(void)
{
	std::vector<std::string> test;
	ft::vectorIterator<std::string> myiterator;
	ft::vectorIterator<std::string> myinterator2;
	std::vector<std::string>::iterator baseiterator;

	myiterator = myinterator2;
	++myiterator;
	myinterator2++;
	++myinterator2;
	myiterator++;
	myinterator2 += 2;
	myiterator += 2;
	if (myiterator == myinterator2)
		std::cout << "equal" << std::endl;
	else if (myiterator != myinterator2)
		std::cout << "no equals" << std::endl;
}

template <typename T>
void	vectorPrinter(ft::vector<T> &v)
{
	typename std::vector<T>::iterator b_iter;
	typename ft::vector<T>::iterator iter;
	int i = 0;

	for (iter = v.begin(); iter != v.end(); v++)
		std::cout << "val line " << i++ << " : " << *iter << std::endl;
}

void	testspace_vector(void)
{
	ft::vector<int>	myvector;
	//ft::vector<int>	myvector2(10);
	ft::vector<std::string> myvector3(100, "bite");
	//vectorPrinter(myvector2);
}

int main(void)
{
	testspace_vector();
	//testspace_iterator();
}