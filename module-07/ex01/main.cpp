#include <iostream>
#include "iter.hpp"

//int main()
//{
//	int intArray[] = {1, 2, 3, 4, 5};
//	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

//	std::cout << "printing int array" << std::endl;
//	iter(intArray, 5, printElement<int>);
//	std::cout << std::endl;

//	std::cout << "print float arrary" << std::endl;
//	iter(doubleArray, 5, printElement<double>);
//	std::cout << std::endl;
//	return (0);
//}

 class Awesome
 {
 	private:
		int _n;

 	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
 };

 std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

 template< typename T >
 void print( T const & x ) { std::cout << x << std::endl; return; }

 int main()
 {
 	int tab[] = { 0, 1, 2, 3, 4 };
 	Awesome tab2[5];
 	::iter( tab, 5, print );
 	::iter( tab2, 5, print );
 	return 0;
 }
