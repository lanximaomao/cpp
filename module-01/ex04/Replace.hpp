#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Replace
{
	public:
		//Replace();
		//~Replace();

		std::string		filename;
		std::string		old_str;
		std::string		new_str;

		void			callReplace(std::ifstream *sourceFile, std::ofstream *destFile);
		//void			setFileName(std::string);
		//void			setOld(std::string);
		//void			setNew(std::string);
		//std::string		getFileName();
		//std::string		getOld();
		//std::string		getNew();
	private:
};

#endif
