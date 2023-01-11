/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:25:12 by vducoulo          #+#    #+#             */
/*   Updated: 2023/01/11 11:09:44 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/Vector.hpp"
# include <vector>

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

void	testspace_vector(void)
{
	ft::vector<int>	myvector;
	ft::vector<int>	myvector2(10);
}

int main(void)
{
	testspace_vector();
	//testspace_iterator();
}