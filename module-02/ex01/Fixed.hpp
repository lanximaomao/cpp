#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed
{
	public:

		Fixed(void);
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed & other);
		Fixed& operator=(const Fixed &other);
		~Fixed();

		int		toInt( void ) const;
		float	toFloat( void ) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:

		int					_fixedPoint;
		static const int	_fractionalBits = 8;
};

// why this cannot placed as a member function?
std::ostream &operator<<(std::ostream &output, const Fixed &i);

#endif
