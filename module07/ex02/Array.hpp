#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	private:
		unsigned int    len;
		T*              array;
	public:
		Array   ( void ): len(0), array(NULL)
		{
		}

		Array    ( unsigned int n ):len(n)
		{
			this->array = new T[n]();
		}
		Array   (Array<T> const & arr):len(arr.len), array(NULL)
		{
			if (this->len)
			{
				this->array = new T[this->len];
				for (unsigned int i = 0; i < this->len; i++)
					this->array[i] = T(arr.array[i]);
			}
		}
		
		class OutOfBoundsException: public std::exception
		{
			virtual const char* what() const throw();
		};

		unsigned int     size( void ) const
		{
			return this->len;
		}
		Array<T> & operator=(Array<T> const &arr)
		{
			if (this->array)
				delete[] array;
			this->len = arr.len;
			if (this->len)
			{
				this->array = new T[this->len];
				for (size_t i = 0; i < this->len; i++)
					this->array[i] = T(arr.array[i]);
			}
			return (*this);
		}
		T      &operator[](unsigned int n)
		{
			if(n >= this->len)
				throw Array::OutOfBoundsException();
			return (this->array[n]);
		}

		T const &operator[](unsigned int n) const
		{
			if(n > this->len)
				throw Array::OutOfBoundsException();
			return (this->array[n]);
		}
		virtual ~Array ( void )
		{
			if (this->array)
				delete[] this->array;
		};


};

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return "ArrayException: trying to access element out of range";
}

#endif