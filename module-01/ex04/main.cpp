#include <iostream>
#include <fstream>

std::string		replace(std::string line, std::string old_str, std::string new_str)
{
	size_t pos = 0;

	while (1)
	{
		pos = line.find(old_str, pos);
		if (pos != std::string::npos)
		{
			line.erase(pos, old_str.length());
			if (!new_str.empty())
				line.insert(pos, new_str);
			pos += new_str.length();
		}
		else
			return (line);
	}
	std::cout << "exiting from replace" << std::endl;
	return(line);
}

/*
**  edge case:
**  old or new str are empty
**  file overwrite
**  old_str is a newline character
**  extremely large file
*/
int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cout << "wrong number of arguments." << std::endl;
		return (1);
	}
	std::string line;
	std::string filename = std::string(argv[1]);
	std::string old_str = std::string(argv[2]);
	std::string new_str = std::string (argv[3]);
	std::ifstream sourceFile(filename);
	if (sourceFile.good())
	{
		std::ofstream destFile(filename.append(".replace"));
		if (destFile.good())
		{
			if (old_str.empty())
				return (0);
			while (getline(sourceFile,line, '\n'))
			{
				if (!sourceFile.eof())
					line.append("\n");
				line = replace(line, old_str, new_str);
				destFile << line;
			}
		}
		else
		{
			std::cout << "Failed to create the file." << std::endl;
			sourceFile.close();
			return (1);
		}
		sourceFile.close();
		destFile.close();
	}
	else
	{
		std::cout << "Fail to open source file.\n";
		return (1);
	}
	return (0);
}
