#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

//A member function int getRawBits( void ) const; that returns the raw value of the fixed-point value.
//A member function void setRawBits( int const raw ); that sets the raw value of the fixed-point number.

class Fixed
{
	public:

		Fixed();
		Fixed(const Fixed & other); // copy constructor
		Fixed & operator=(const Fixed &other); // copy assignment operator overload
		~Fixed();

		int					getRawBits(void) const;
		void				setRawBits(int const raw);

	private:

		int					_num;
		static const int	_fractionalBits = 8;

		std::ostream & operator<<(const Fixed &i);
};


#endif
