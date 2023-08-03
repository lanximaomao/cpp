#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed
{
	public:

		Fixed(void);
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed & other); // copy constructor
		Fixed & operator=(const Fixed &other); // copy assignment operator overload
		~Fixed();

		// 6 comparison operators: >, <, >=, <=, == and !=
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		// 4 arithmetic operators: +, -, *, and /.
		Fixed operator+(const Fixed &other);
		Fixed operator-(const Fixed &other);
		Fixed operator*(const Fixed &other);
		Fixed operator/(const Fixed &other);

		// 4 increment/decrement (pre-increment and post-increment,
		// pre-decrement and post-decrement) operators, that will increase or
		// decrease the fixed-point value from the smallest representable ε such as 1 + ε > 1.
		// what?
		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);


		// what is static and static const?
		static Fixed		&min(Fixed &f1, Fixed &f2);
		static const Fixed	&min(const Fixed &f1, const Fixed &f2);
		static Fixed		&max(Fixed &f1, Fixed &f2);
		static const Fixed	&max(const Fixed &f1, const Fixed &f2);

		int		toInt( void ) const;
		float	toFloat( void ) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					_fixedPoint;
		static const int	_fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &output, const Fixed &i); // why this cannot placed as a member function?

#endif
