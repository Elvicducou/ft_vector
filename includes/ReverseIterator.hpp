
namespace ft
{
	template <typename T>
	class ReverseIterator : public T
	{
		public :

			using typename T::value_type;
			using typename T::pointer;
			using typename T::pointer_const;
			using typename T::reference;
			using typename T::reference_const;
			using typename T::difference_type;
		
			ReverseIterator	()											{};
			ReverseIterator (ReverseIterator const &rhs) : T(rhs._p) 	{};
			ReverseIterator (T const &rhs)				 : T(rhs) 					{};
			ReverseIterator &operator=(ReverseIterator const &rhs)
			{	return (this->_p = rhs._p, *this);				}
			
			reference operator*(void) const
			{	return (_p);									}
	}
}