#include "Replace.hpp"

//#include "Replace.hpp"
// memory leak?
static int if_match(std::string buf, std::string target)
{
	for (size_t i = 0; i < buf.length(); i++)
	{
		//std::cout << "buf=" << buf << "; len=" << buf.length() << std::endl;
		for (size_t j = 0; j < target.length() - 1; j++)
		{
			//std::cout << i << " && " << j << std::endl;
			if (buf[i+j] != target[j])
				break;
			if (j == target.length() - 2)
			{
				//std::cout << i << " && " << j << std::endl;
				return (i);
			}
		}
	}
	return (-1);
}

// back gives the last character in a string
// what if the replaced string is a null?
void		Replace::callReplace(std::ifstream *sourceFile, std::ofstream *destFile)
{
	std::string buf;
	char lastChar = this->old_str.back();

	while (std::getline(*sourceFile, buf, lastChar))
	{
		//std::cout << "buf=" << buf << std::endl;
		if (buf.length() + 1 >= this->old_str.length())
		{
			int i = if_match(buf, this->old_str);
			if (i != -1)
			{
				std::string before;

				//std::cout << "match! buf = " << buf << std::endl;
				if (i > 0)
					before = buf.substr(0, i);
				else
					before = new_str;
				*destFile << before.append(new_str);
			}
		}
		else
			*destFile << buf << lastChar;
	}
}

// handel unexpected inputs and errors
// std::ios::out | std::ios::trunc means if the file should be open for output and if the file exisit, it should be overwritten.
int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cout << "wrong number of arguments." << std::endl;
		return (1);
	}
	//parsing
	Replace sed;

	sed.filename = std::string(argv[1]);
	sed.old_str = std::string(argv[2]);
	sed.new_str = std::string(argv[3]);

	//check if filename is valid

	std::ifstream sourceFile(sed.filename);
	if (sourceFile.is_open())
	{
		// create a new file for output
		//what if this file exi
		std::ofstream destFile(sed.filename.append(".replace"), std::ios::out | std::ios::trunc);
		if (destFile.is_open())
		{
			// copy file
			//destFile << sourceFile.rdbuf();// copy the content
			sed.callReplace(&sourceFile, &destFile);
		}
		else
		{
			std::cout << "Failed to create the file." << std::endl;
			sourceFile.close(); // close sourceFile
			std::exit(1); // error code?
		}
		//close two files
		sourceFile.close();
		destFile.close();
	}
	else // fail to open
	{
		std::cout << "Failed to open the file." << std::endl;
		std::exit(1);
	}
	return (0);
}
