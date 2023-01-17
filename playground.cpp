/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playground.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:25:15 by vducoulo          #+#    #+#             */
/*   Updated: 2023/01/17 15:45:45 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <iostream>
# include <vector>
# include <time.h>
# include <iomanip>

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

void stackshower (void)
{
	std::vector<int> *vec = new std::vector<int>;
	std::vector<int>::iterator backptr = vec->begin();
	int todd = 0;
	clock_t timerst;
	clock_t timerend;
	for (int i = 0; i < 5; i++)
	{
		timerst = clock();
		vec->push_back(todd++);
		timerend = clock();
		std::cout << red << "exec took "<< std::setprecision(10) << double((timerend - timerst)) << " micro s" << reset << std::endl;
		if (backptr != vec->begin())
		{
			std::cout << red << "data migred" << std::endl << reset;
			backptr = vec->begin();
		}
		std::cout << "vec_ptr addr : " << &vec << ", vec_ptr pointed addr : " << vec << std::endl;
		for (std::vector<int>::iterator iter = vec->begin(); iter != vec->end(); ++iter)
		{
			std::cout << *iter << " : " << &iter << " : " << &(*iter) << std::endl;
		}
	}
	
}

void	vectorplayground(void)
{
	std::vector<std::string> test;
	test.push_back("bite");
	test.push_back("prout");
	std::cout << "\n\n ITERATOR \n\n";
	for (std::vector<std::string>::iterator iter = test.begin(); iter != test.end(); iter++)
		std::cout << *iter << ", pointer : " << &iter << std::endl;
	std::cout << "size : " << test.size() << ", max size : " << test.max_size() << ", capacity : " << test.capacity() << std::endl;

}

int main(void)
{
	stackshower();
	vectorplayground();
}