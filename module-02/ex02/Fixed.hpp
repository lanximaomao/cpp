#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed
{
	public:

		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed & other);
		Fixed& operator=(const Fixed &other);
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

		// 4 increment/decrement (pre-increment and post-increment

		Fixed &operator++(); //  Pre-increment
		Fixed operator++(int); // post-increment
		Fixed &operator--(); // pre-decrement
		Fixed operator--(int); // post-decrement

		static Fixed		&min(Fixed &f1, Fixed &f2);
		static const Fixed	&min(const Fixed &f1, const Fixed &f2);
		static Fixed		&max(Fixed &f1, Fixed &f2);
		static const Fixed	&max(const Fixed &f1, const Fixed &f2);

		int		toInt( void ) const;
		float	toFloat( void ) const;
		int		getRawBits() const;
		void	setRawBits(int const raw);

	private:
		int					_fixedPoint;
		static const int	_fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &output, const Fixed &i);

#endif
