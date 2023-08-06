#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:

		Fixed();
		Fixed(const Fixed& other); // copy constructor
		Fixed & operator=(const Fixed &other); // copy assignment operator overload
		~Fixed();

		int					getRawBits() const;
		void				setRawBits(int const raw);

	private:
		int					_fixedPoint;
		static const int	_fractionalBits = 8;
};


#endif
