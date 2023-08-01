#include <iostream>
#include <fstream>

std::string		replace(std::string line, std::string old_str, std::string new_str)
{
	int pos = 0;

	//std::cout << line << std::endl;
	//std::cout << old_str << std::endl;
	//std::cout << new_str << std::endl;
	while (line.find(old_str, pos) != std::string::npos)
	{
		line.erase(pos, old_str.length());
		std::cout << line << std::endl;
		line.insert(pos, new_str);
		std::cout << line << std::endl;
		pos += new_str.length();
		std::cout << "pos=" << pos << std::endl;
	}
	return(line);
}

// handel unexpected inputs and errors
// std::ios::out | std::ios::trunc means if the file should be open for output and if the file exisit
// it should be overwritten.
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

	if (sourceFile)
	{
		std::ofstream destFile(filename.append(".replace"));
		if (destFile)
		{
			while (getline(sourceFile,line))
			{

				line.append("\n");
				line = replace(line, old_str, new_str);
				destFile << line;
			}
		}
		else
		{
			std::cout << "Failed to create the file." << std::endl;
			sourceFile.close();
			std::exit(1);
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
