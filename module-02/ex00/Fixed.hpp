#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

// Orthodox Canonical class form

class Fixed
{
	public:

	private:
		int a_fix;
		static const int fb = 8;
	public:


};

// requirment for public members

//◦ A default constructor that initializes the fixed-point number value to 0.
//◦ A copy constructor.
//◦ A copy assignment operator overload.
//◦ A destructor.
//◦ A member function int getRawBits( void ) const; that returns the raw value of the fixed-point value.
//◦ A member function void setRawBits( int const raw ); that sets the raw value of the fixed-point number.


#endif
