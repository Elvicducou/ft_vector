#ifndef CPP_VECTOR_HPP
# define CPP_VECTOR_HPP

#include "VectorIterator.hpp"
#include "ReverseIterator.hpp"

namespace ft
{

	template<typename T>
	class Vector
	{
		public :

		typedef T 							value_type;
		typedef T 							*pointer;
		typedef T const 					*const_pointer;
		typedef T 							&reference;
		typedef T const 					&const_reference;
		typedef	std::ptrdiff_t				difference_type;
		typedef std::size_t					size_type;
		typedef VectorIterator<T>			iterator;
		typedef VectorIterator<T> const 	const_iterator;
		typedef ReverseIterator<T>			reverse_iterator;
		typedef ReverseIterator<T> const	const_reverse_iterator;

		private :

		pointer 							_p;
		size_type							_size;
		size_type							_capacity;

		public :

		Vector	() : _p(nullptr), _size(0), _capacity(0)	{};
		Vector	(size_type n, const T& value)
		~Vector	()	{};

		Vector	&operator=(Vector const &rhs)
		{	_p = rhs._p;
			_size = rhs._size;
			_capacity = rhs._capacity;
			return (*this);
		}
		
	};

}
#endif