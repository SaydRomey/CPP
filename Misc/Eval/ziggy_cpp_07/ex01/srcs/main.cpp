/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:07:54 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/05/09 13:29:55 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/whatever.hpp" 
#include "stdio.h"


// int main()
// {
// 	int a = 2;
// 	int b = 3;
// 	::swap( a, b );
// 	cout << "a = " << a << ", b = " << b << endl;
// 	cout << "min( a, b ) = " << ::min( a, b ) << endl;
// 	cout << "max( a, b ) = " << ::max( a, b ) << endl;
// 	string c = "chaine1";
// 	string d = "chaine2";
// 	::swap(c, d);
// 	cout << "c = " << c << ", d = " << d << endl;
// 	cout << "min( c, d ) = " << ::min( c, d ) << endl;
// 	cout << "max( c, d ) = " << ::max( c, d ) << endl;

// 	cout << endl << "Creating int array, printing and incrementing:" << endl;
// 	int arr[5] = {1,2,3,4,5};
// 	cout.setf(std::ios::fixed, std::ios::floatfield);
// 	cout << std::setprecision(1);
// 	cout << endl;
// 	iter(arr, 5, &print);
// 	cout << endl;
// 	iter(arr, 5, &increment);
// 	for (int i = 0; i < 5; i++)
// 		cout << arr[i] << " ";
// 	cout << endl << endl;

// 	cout << "Creating double array, printing and incrementing:" << endl;
// 	double arr2[5] = {1,2,3,4,5};
// 	cout << endl;
// 	iter(arr2, 5, &print);
// 	cout << endl;
// 	iter(arr2, 5, &increment);
// 	for (int i = 0; i < 5; i++)
// 		cout << arr2[i] << " ";
// 	cout << endl << endl;

// 	cout << "Creating float array, printing and incrementing:" << endl;
// 	float arr3[5] = {1.0f,2.0f,3.0f,4.0f,5.0f};
// 	cout << endl;
// 	iter(arr3, 5, &print);
// 	cout << endl;
// 	iter(arr3, 5, &increment);
// 	for (int i = 0; i < 5; i++)
// 		cout << arr3[i] << " ";
// 	cout << endl << endl;

// 	cout << "Creating char array, printing and incrementing:" << endl;
// 	char arr4[5] = {'A','B','C','D','E'};
// 	cout << endl;
// 	iter(arr4, 5, &print);
// 	cout << endl;
// 	iter(arr4, 5, &increment);
// 	for (int i = 0; i < 5; i++)
// 		cout << arr4[i] << " ";
// 	cout << endl << endl;

// 	cout << "Creating string array, printing:" << endl;
// 	string arr5[5] = {"one", "two", "three", "four", "five"};
// 	cout << endl;
// 	iter(arr5, 5, &print);
// 	cout << endl;
// 	// iter(arr5, 5, &increment);
// 	// for (int i = 0; i < 5; i++)
// 	// 	cout << arr5[i] << " ";
// 	cout << endl << endl;
// 	return (0);
// }


class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };  // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
  Awesome tab2[5];

  iter( tab, 5, print<int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}
