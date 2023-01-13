/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:25:12 by vducoulo          #+#    #+#             */
/*   Updated: 2023/01/13 22:11:57 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/Vector.hpp"
# include <vector>
# include <iostream>
# include <array>

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

void	range_vector_constructor_test(void)
{
	std::array<int, 5> arr = {1, 2, 3, 4, 5};
	ft::vector<int> vec(arr.begin(), arr.end());
	for (ft::vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
		std::cout << *iter << std::endl;
}

void	testspace_vector(void)
{
	ft::vector<int>	myvector;
	//ft::vector<int>	myvector2(10, 10);
	ft::vector<std::string> myvector3(10, "bite");
	myvector3.resize(8, "prout");
	//myvector3.reserve(300000);
	myvector3.resize(10, "prout");
	//std::cout << "out : " << myvector3[11] << std::endl;
	std::cout << "vec3 capacity : " << myvector3.capacity() << std::endl;
	myvector3.assign(2, "ouille ouille ouille");
	myvector3.push_back("test0");
	myvector3.push_back("test1");
	myvector3.push_back("test2");
	myvector3.pop_back();
	myvector3.insert(myvector3.begin(), 5, "new");
	//myvector3.insert(myvector3.begin(), "WAOOOOOOOOOU");
	for (ft::vectorIterator<std::string> iter = myvector3.begin(); iter != myvector3.end(); iter++)
	{
		std::cout << "print : " << *iter << std::endl;
	}
}

int main(void)
{
	testspace_vector();
	//testspace_iterator();
	//range_vector_constructor_test();
}