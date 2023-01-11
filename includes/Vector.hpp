#ifndef CPP_VECTOR_HPP
# define CPP_VECTOR_HPP

#include "VectorIterator.hpp"
#include "ReverseIterator.hpp"
#include <memory>

namespace ft
{
	template<typename T>
	class reverseIterator
	{

	};

	template<typename T, class Alloc = std::allocator<T> >
	class vector
	{
		public :

		typedef T 											value_type;
		typedef std::allocator<T>							allocator_type;
		typedef typename allocator_type::pointer 			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::reference 			reference;
		typedef typename allocator_type::const_reference  	const_reference;

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
		allocator_type						_allocator;

		public :


		//			Constructor and Destructors				//


		explicit vector (const allocator_type& alloc = allocator_type()) 
		: _p(nullptr), _size(0), _capacity(0), _allocator(alloc)	{};

		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: _allocator(alloc), _size(n), _capacity(n)
		{
			_p = _allocator.allocate(n);
			for (size_t i = 0; i < _size; i++)
				_p[i] = val;
		};

		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		: _allocator(alloc), _p(nullptr), _size(0), _capacity(0)
		{
			std::cout << "called" << std::endl;
			_p = nullptr; // debug
		};
		
		vector (const vector& x)
		{ };

		~vector	()
		{
			this->clear();
			_allocator.deallocate(_p, _size);
		};

		//			End of Constructors / Destructors		//

		//			Operator Overload						//
		
		vector	&operator=(vector const &rhs)
		{	_p = rhs._p;
			_size = rhs._size;
			_capacity = rhs._capacity;
			return (*this);
		}

		//			End of Operator overload				//

		template <class InputIterator>
  		void assign (InputIterator first, InputIterator last)
		{

		}

		void assign (size_type n, const value_type& val)
		{
			this->clear;
			this->resize(n, val);
		}

		void clear(void)
		{
	
		}
	};

}
#endif