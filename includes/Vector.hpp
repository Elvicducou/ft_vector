/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:10:41 by vducoulo          #+#    #+#             */
/*   Updated: 2023/01/31 18:41:40 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_VECTOR_HPP
# define CPP_VECTOR_HPP

#include "./Iterators/RandomAccessIterator.hpp"
#include "./Iterators/ReverseIterator.hpp"
#include "project.hh"
#include <memory>

namespace ft
{
	template<typename T, class Alloc = std::allocator<T> >
	class vector
	{
		public :

		typedef T 																value_type;
		typedef Alloc															allocator_type;
		typedef typename allocator_type::pointer 								pointer;
		typedef typename allocator_type::const_pointer							const_pointer;
		typedef typename allocator_type::reference 								reference;
		typedef typename allocator_type::const_reference  						const_reference;
		typedef typename allocator_type::size_type								size_type;

		typedef typename ft::random_access_iterator<value_type>					iterator;
		typedef typename ft::random_access_iterator<value_type const>			const_iterator;
		typedef	typename ft::iterator_traits<iterator>::difference_type			difference_type;
		typedef reverse_iterator<const_iterator>								const_reverse_iterator;
		typedef reverse_iterator<iterator>										reverse_iterator;

		private :

		pointer 							_p;
		size_type							_size;
		size_type							_capacity;
		allocator_type						_allocator;

		public :


		//			Constructor and Destructors				//


		explicit vector (const allocator_type& alloc = allocator_type()) 
		: _p(nullptr), _size(0), _capacity(0), _allocator(alloc)
		{
			_p = _allocator.allocate(_size);
			//std::cout << "entered default constructor" << std::endl;
		};

		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: _size(n), _capacity(n), _allocator(alloc)
		{
			_p = _allocator.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(_p + i, val);
		};

		template <class InputIterator> //totest
		vector (typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::istrue first,
		InputIterator last, const allocator_type& alloc = allocator_type())
		: _p(nullptr), _size(0), _capacity(0), _allocator(alloc)
		{
			//std::cout << "entered range constructor, first : " << *first << std::endl;
			_p = _allocator.allocate(_size);
			assign(first, last);
		};
		
		vector (const vector& rhs) : _p(nullptr), _size(0), _capacity(0), _allocator(rhs._allocator)
		{
			_p = _allocator.allocate(_size);
			*this = rhs;
		};

		~vector	()
		{
			//std::cout << "destructor called" << std::endl;
			if (_size)
				this->clear();
			_allocator.deallocate(_p, _capacity);
			_p = nullptr;
			_capacity = 0;
		};

		//			End of Constructors / Destructors		//

		//			Operator Overload						//
		
		vector	&operator=(vector const &rhs)		//tocomplete // totest after rewrite
		{	
			if (this != &rhs)
			{
				clear();
				_allocator.deallocate(_p, _capacity);
				_allocator = rhs._allocator;
				_size = rhs._size;
				_p = _allocator.allocate(_size);
				_capacity = rhs._capacity;
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(_p + i, *(rhs._p + i));
				//std::cout << "operator = done, size : " << _size << std::endl;
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
			if (n > _capacity)
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
			return (_size ? false : true);
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
				if (_size)
				{	for (size_type i = _size; i;)
						_allocator.destroy(_p + --i);
				}
				_allocator.deallocate(_p, _capacity);
				_capacity = n;
				_p = tmp_p;
			}
		}

		//			End of Capacity							//

		//			Element Access							//

		reference operator[] (size_type n)
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
			if (n >= _size)
			{
				//std::cout << "EXECPTION !!!" << std::endl;
				throw (std::out_of_range("out of range"));
			}
			return (*(_p + n));
		}

		const_reference at (size_type n) const
		{
			if (n >= _size)
				throw (std::out_of_range("out of range"));
			return (*(_p + n));
		}

		reference front(void)
		{
			return (*_p);
		}

		const_reference front() const
		{
			return (*_p);
		}

		reference back()
		{
			return (*(_p + _size - 1));
		}

		const_reference back() const
		{
			return (*(_p + _size - 1));
		}

		//			End of Access						//

		//			Modifiers							//

		template <class InputIterator>
  		void assign (InputIterator first, InputIterator last)
		{
			typename ft::iterator_traits<InputIterator>::iterator_category ite_category;
			_assign(first, last, ite_category);
			
		}

		void assign (size_type n, const value_type& val)
		{
			this->clear();
			this->resize(n, val);
		}

		void clear (void)
		{
			//std::cout << "entering clear function from " << from << ", size : " << _size << std::endl;
			while (_size)
			{
				//std::cout << "entered loop" << std::endl;
				_allocator.destroy(_p + --_size);
			}
			//std::cout << "clearing ! new size : " << _size << std::endl;
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
				_allocator.destroy(_p + --_size);
				//std::cout << "pop_back ! new size : " << _size << std::endl;
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
    	void insert (iterator position, typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::istrue first,
		InputIterator last)
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
			return (last - 1);
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

		private :
		
		template <class InputIterator>
		void _assign(InputIterator first, InputIterator last, ft::input_iterator_tag)
		{
			if (_size)
				clear();
			for (; first != last; first++)
				push_back(*first);
		}
		
		template <class InputIterator>
		void _assign(InputIterator first, InputIterator last, std::input_iterator_tag)
		{
			if (_size)
				clear();
			for (; first != last; first++)
				push_back(*first);
		}
		
		template <class InputIterator, class IteratorCategory>
		void _assign(InputIterator first, InputIterator last, IteratorCategory)
		{
			size_t diff = ft::iterator_diff(first, last);
			if (_size)
				clear();
			if (diff > _capacity)
				reserve(diff);
			_size = diff;
			for (size_type i = 0; first != last; first++)
				_allocator.construct(_p + i++, *first);
		}
		
	}; // End of class Vector

	//		Relational operators (non members)	//

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	};

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() > rhs.size())
			return (false);
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (!(lhs == rhs))
			return (lhs < rhs);
		else
			return (true);
	}

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() < rhs.size() || lhs == rhs)
			return (false);
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
  	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (!(lhs == rhs))
			return (!(lhs < rhs));
		else
			return (true);
	}

	//		End of relational operators			//

}
#endif