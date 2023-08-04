#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:

		Fixed(void);
		Fixed(const Fixed& other); // copy constructor
		Fixed & operator=(const Fixed &other); // copy assignment operator overload
		~Fixed();

		int					getRawBits(void) const;
		void				setRawBits(int const raw);

	private:
		int					_fixedPoint;
		static const int	_fractionalBits = 8;
};


#endif
