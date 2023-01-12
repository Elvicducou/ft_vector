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
		
		vector (const vector& x)	//todo
		{ };

		~vector	()
		{
			this->clear();
			_allocator.deallocate(_p, _size);
		};

		//			End of Constructors / Destructors		//

		//			Operator Overload						//
		
		vector	&operator=(vector const &rhs)		//tocomplete
		{	_p = rhs._p;
			_size = rhs._size;
			_capacity = rhs._capacity;
			return (*this);
		}

		//			End of Operator overload				//

		template <class InputIterator>
  		void assign (InputIterator first, InputIterator last)		//todo
		{

		}

		void assign (size_type n, const value_type& val)
		{
			this->clear;
			this->resize(n, val);
		}

		void clear(void)			//todo
		{
			std::cout << "hihihi alors normalement on clear ici" << std::endl;
		}

		//			Iterators								//

		iterator begin(void)
		{
			return (iterator(_p));
		}

		const_iterator begin(void) const
		{
			return (const_iterator(_p));
		}

		reverse_iterator rbegin(void)
		{
			return (reverse_iterator(_p));
		}

		const_reverse_iterator rbegin(void) const
		{
			return (const_revrese_iterator(_p));
		}

		iterator end(void)
		{
			return (iterator(_p + _size));
		}

		const_iterator	end(void) const
		{
			return (const_iterator(_P + _size));
		}

		reverse_iterator rend(void)
		{
			return (reverse_iterator(_p + _size));
		}

		const_reverse_iterator rend(void) const
		{
			return (const_resverse_iterator(_P + _size));
		}

		//			End of Iterators						//

		//			Capacity								//

		size_type size(void) const
		{
			return (_size);
		}

		size_type max_size(void) const
		{
			return (_allocator.max_size());
		}

		void resize(size_type n, value_type val = value_type())	//todo
		{

		}

		size_type capacity(void) const
		{
			return (_capacity);
		}

		bool empty(void) const
		{
			return (_size ? true : false);
		}

		void reserve(size_type n)			//todo
		{

		}

		//			End of Capacity							//
	};

}
#endif