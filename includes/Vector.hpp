#ifndef CPP_VECTOR_HPP
# define CPP_VECTOR_HPP

#include "VectorIterator.hpp"
#include "ReverseIterator.hpp"
#include "project.hh"
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
		: _size(n), _capacity(n), _allocator(alloc)
		{
			_p = _allocator.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(_p + i, val);
		};

		template <class InputIterator> //totest
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		: _allocator(alloc)
		{
			assign(first, last);
		};
		
		vector (const vector& rhs)	//todo
		{
			_allocator = rhs._allocator;
			_size = rhs._size;
			_p = _allocator.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(_p + i, *(rhs._p + i));
		};

		~vector	()
		{
			this->clear();
		};

		//			End of Constructors / Destructors		//

		//			Operator Overload						//
		
		vector	&operator=(vector const &rhs)		//tocomplete // totest after rewrite
		{	
			if (this != &rhs)
			{
				clear();
				_allocator = rhs._allocator;
				_size = rhs._size;
				_p = _allocator.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(_p + i, *(rhs._p + i));
			}
			return (*this);
		}

		//			End of Operator overload				//

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
			return (const_iterator(_p + _size));
		}

		reverse_iterator rend(void)
		{
			return (reverse_iterator(_p + _size));
		}

		const_reverse_iterator rend(void) const
		{
			return (const_reverse_iterator(_p + _size));
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

		void resize(size_type n, value_type val = value_type())	//totest //DRASTIC CHANGE NEEDED
		{
			if (n >= _capacity)
			{
				pointer tmp_p = _allocator.allocate(n);
				for (size_t i = 0; i < n; i++)
				{
					if (i < _size)
						_allocator.construct(tmp_p + i, *(_p + i));
					else
						_allocator.construct(tmp_p + i, val);
				}
				_allocator.deallocate(_p, _capacity);
				_p = tmp_p;
				_capacity = n;
			}
			else if (n < _size)
				while (_size > n)
					pop_back();
			else if (n > _size)
				while (_size < n)
					push_back(val);
			_size = n;
		}

		size_type capacity(void) const
		{
			return (_capacity);
		}

		bool empty(void) const
		{
			return (_size ? true : false);
		}

		void reserve(size_type n)			//totest
		{
			if (n > _capacity)
			{
				pointer tmp_p = _allocator.allocate(n);
				for (size_t i = 0; i < n; i++)
				{
					if (i < _size)
						_allocator.construct(tmp_p + i, *(_p + i));
				}
				_allocator.deallocate(_p, _capacity);
				_capacity = n;
				_p = tmp_p;
			}
		}

		//			End of Capacity							//

		//			Element Access							//

		reference operator[] (size_type n) // better with return( this->_P[]) ? 
		{
			// need for std::exeption ?
			return (*(_p + n));
		}

		const_reference operator[] (size_type n) const
		{
			// need for std::exeption ?
			return (*(_p + n));
		}

		reference at (size_type n)
		{
			if (n > _size)
				throw (std::out_of_range("out of range"));
			return (*(_p + n));
		}

		const_reference at (size_type n) const
		{
			if (n > _size)
				throw (std::out_of_range("out of range"));
			return (*(_p + n));
		}

		reference front(void)
		{
			return (_p);
		}

		const_reference front() const
		{
			return (_p);
		}

		reference back()
		{
			return (_p + _size);
		}

		const_reference back() const
		{
			return (_p + _size);
		}

		//			End of Access						//

		//			Modifiers							//

		template <class InputIterator>
  		void assign (InputIterator first, InputIterator last) //totest
		{
			if (ft::iterator_diff(first, last) > _capacity)
				reserve(ft::iterator_diff(first, last));
			_size = ft::iterator_diff(first, last);
			_capacity = _size;
			for (size_type i = 0; first != last; first++)
				_allocator.construct(_p + i++, *(first));
		}

		void assign (size_type n, const value_type& val) //totest
		{
			this->clear();
			this->resize(n, val);
		}

		void clear (void)
		{
			_allocator.deallocate(_p, _capacity);
			_size = 0;
			_capacity = 0;
			_p = nullptr;
		}

		void push_back (const value_type& val)
		{
			if (_size == _capacity)
				this->reserve(_capacity + 4);
			_allocator.construct(_p + _size, val);
			_size++;
		}

		void pop_back (void)
		{
			if (_size)
			{
				_size --;
			}
		}

		iterator insert (iterator position, const value_type& val) // give a return value
		{
			difference_type diff = position - this->begin();
			insert(position, 1, val);
			return (begin() + diff);
		}

    	void insert (iterator position, size_type n, const value_type& val)
		{
			difference_type diff = position - this->begin();
			value_type tmp;
			this->resize(_size + n, val);
			iterator iter = begin() + diff;
			iterator iter_end = end();
			while (iter_end - n != iter)
				tmp = *(iter_end - 1), *(iter_end - 1) = *(iter_end - 1 - n), *(iter_end - 1 - n) = tmp, iter_end--;
		}

		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				position = insert(position, *first);
				position++, first++;
			}
		}

		iterator erase (iterator position)
		{
			return(erase(position, position + 1));
		}

		iterator erase (iterator first, iterator last)
		{
			difference_type diff = last - first;
			size_t			new_size = _size - diff;
			iterator 		iter(last);
		
			while (iter != end())
				*first = *iter, iter++, first++;
			while (_size > new_size)
				pop_back();
			return (last);
		}

		void swap (vector& x)
		{
			ft::exchange(_p, x._p);
			ft::exchange(_size, x._size);
			ft::exchange(_capacity, x._capacity);
		}

		//		End of Modifiers					//

		//		Allocator							//

		allocator_type get_allocator() const
		{
			return(_allocator);
		}

		//		End of Allocator					//
	};

}
#endif