#include <iostream>
#include "functions.hpp"

//int main( void )
//{
//	int a = 2;
//	int b = 3;

//	::swap( a, b );
//	std::cout << "a = " << a << ", b = " << b << std::endl;
//	std::cout << "min( a, b ) = " << ::min<int>( a, b ) << std::endl;
//	std::cout << "max( a, b ) = " << ::max<int>( a, b ) << std::endl;

//	std::string c = "chaine1";
//	std::string d = "chaine2";
//	std::cout << "c = " << c << ", d = " << d << std::endl;
//	std::cout << "min( c, d ) = " << ::min<std::string>( c, d ) << std::endl;
//	std::cout << "max( c, d ) = " << ::max<std::string>( c, d ) << std::endl;
//	return 0;
//}

 class Awesome
 {
	private:
		int _n;

	public:
		Awesome(void) : _n(0) {}
		Awesome( int n ) : _n( n ) {}
		Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
		int get_n() const { return _n; }
 };

 std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

 int main(void)
 {
	Awesome a(2), b(4);
	swap(a, b);
	std::cout << a << " " << b << std::endl;
	std::cout << max(a, b) << std::endl;
	std::cout << min(a, b) << std::endl;
	return (0);
 }
