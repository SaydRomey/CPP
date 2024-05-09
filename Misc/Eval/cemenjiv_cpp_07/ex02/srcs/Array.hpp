#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template < typename T >
class Array
{

	public:

		Array(): _array(NULL), _arraySize(0){
			std::cout << "[DEFAULT CONSTRUCTOR] has been called" << std::endl;
		}
		Array(unsigned int n): _arraySize(n){
			std::cout << "[CONSTRUCTOR WITH ARG] has been called" << std::endl;
			_array = new T[n];
		}
		Array( Array const & src ) {
			std::cout << "[COPY CONSTRUCTOR WITH ARG] has been called" << std::endl;
			_array = NULL; 
			*this = src;
		}
		~Array(){
			std::cout << "[DESTRUCTOR] has been called" << std::endl;
			delete[] _array;
		}

		Array &		operator=( Array const & rhs ){
			std::cout << "[ASSIGNMENT OPERATOR] has been called" << std::endl;
			if ( this != &rhs ){
				_arraySize = rhs._arraySize;
				_array = new T[rhs._arraySize];
				std::memcpy(_array, rhs._array, rhs._arraySize * sizeof(T));
			}
			return *this;
		}

		T &			operator[](unsigned int index)
		{
			if (index >= _arraySize)
				throw std::invalid_argument("Index is invalid. Index is out of bound");
			return _array[index];
		}

		void	print_array(void)
		{
			std::cout << "The address of array is: " << _array << std::endl;
			for (unsigned int i = 0; i < _arraySize; i++)
				std::cout << _array[i] << std::endl;
		}

		unsigned int size(void){
			return _arraySize;
		}

	private:

		T*				_array;
		unsigned int	_arraySize;

};

#endif /* *********************************************************** ARRAY_H */