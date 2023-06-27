#include "Replace.hpp"

static int if_match(std::string buf, std::string target)
{
	for (size_t i = 0; i < buf.length(); i++)
	{
		for (size_t j = 0; j < target.length(); j++)
		{
			if (buf[i+j] != target[j])
				break;
			if (j == target.length() - 1)
				return (i);
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
		if (buf.length() >= this->old_str.length())
		{
			int i = if_match(buf, this->old_str);
			if (i != -1)
			{
				std::string before = buf.substr(0, i);
				std::string after = buf.substr(i + old_str.length(), buf.length() - i - old_str.length());
				buf = before.append(new_str).append(after);
			}
		}
		destFile << buf << lastChar;
	}
}
