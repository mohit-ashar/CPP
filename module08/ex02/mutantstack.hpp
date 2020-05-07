#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
#include <iostream>
#include <stack>
#include <cstddef>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack( void );
		MutantStack(MutantStack const & ms);
		MutantStack const & operator=(MutantStack const & ms);
		virtual ~MutantStack( void );
		
		class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
		{
			private:
				MutantStack *rhs;
				size_t index = 0;
			public:
				iterator( void );
				iterator( iterator const &other );
				iterator(MutantStack &st, size_t i);
				~iterator();
				T &operator*();//const ?
				iterator &operator=(iterator const &other);
				iterator & operator++();
				iterator operator++(int);
				iterator & operator--();
				iterator operator--(int);
				bool     operator!=(iterator const &rhs);
				bool     operator==(iterator const &rhs);
		};
		iterator end();
		iterator begin();
};


template <typename T>
MutantStack<T>::MutantStack( void ):std::stack<T>()
{
}

template <typename T>
MutantStack<T>::~MutantStack( void )
{
}
template <typename T>
MutantStack<T>::MutantStack(MutantStack const &ms): std::stack<T>(ms.c)
{
}

template <typename T>
MutantStack<T> const & MutantStack<T>::operator=(MutantStack const & ms)
{
    this->c = ms.c;
    return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (iterator(*this,0));
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (iterator(*this, this->size()));
}

template <typename T>
MutantStack<T>::iterator::iterator(): rhs(NULL), index(0)
{
}

template <typename T>
MutantStack<T>::iterator::iterator(iterator const &other) : rhs(other.rhs), index(other.index)
{
}

template <typename T>
MutantStack<T>::iterator::iterator(MutantStack &st, size_t i) : rhs(&st), index(i)
{
}

template <typename T>
MutantStack<T>::iterator::~iterator()
{
}

template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator=(iterator const &other)
{
	this->rhs = other.rhs;
	this->index = other.index;
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator++()
{
	if (this->index < this->rhs->size())
		this->index++;
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator++(int)
{
	iterator tmp(*this);

	++this->index;
	return (tmp);
}

template <typename T>
typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator--()
{
	if (this->index > 0)
		this->index--;
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::iterator::operator--(int)
{
	iterator tmp(*this);

	--this->index;
	return (*this);
}

template <typename T>
bool MutantStack<T>::iterator::operator==(iterator const &other)
{
	return (this->index == other.index);
}

template <typename T>
bool MutantStack<T>::iterator::operator!=(iterator const &other)
{
	return (this->index != other.index);
}

template <typename T>
T &MutantStack<T>::iterator::operator*()
{
	return (this->rhs->c[this->index]);
}

#endif