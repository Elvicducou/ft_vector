#ifndef CPP_VECTOR_HPP
# define CPP_VECTOR_HPP

#include "VectorIterator.hpp"
#include "ReverseIterator.hpp"

namespace ft
{
	template<typename T>
	class reverseIterator
	{

	};

	template<typename T, class Alloc = std::allocator<T>>
	class vector
	{
		public :

		typedef T 											value_type;
		typedef Alloc										allocator_type;
		typedef allocator_type::pointer 					pointer;
		typedef allocator_type::const_pointer				const_pointer;
		typedef allocator_type::reference 					reference;
		typedef allocator_type::const_reference  			const_reference;

		typedef	std::ptrdiff_t								difference_type;
		typedef std::size_t									size_type;
		typedef vectorIterator<value_type>					iterator;
		typedef vectorIterator<value_type> const 			const_iterator;
		typedef reverseIterator<iterator>					reverse_iterator;
		typedef reverseIterator<const_iterator> const		const_reverse_iterator;

		private :

		pointer 							_p;
		size_type							_size;
		size_type							_capacity;

		public :

		explicit vector (const allocator_type& alloc = allocator_type()) 
		: _p(nullptr), _size(0), _capacity(0)	{};

		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: _p(nullptr), _size(0), _capacity(0)	{};

		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		: _p(nullptr), _size(0), _capacity(0)	{};

		vector	(size_type n, const T& value)
		: _p(nullptr), _size(0), _capacity(0)	{};
		
		~vector	()	{};

		vector	&operator=(Vector const &rhs)
		{	_p = rhs._p;
			_size = rhs._size;
			_capacity = rhs._capacity;
			return (*this);
		}
		
	};

}
#endif