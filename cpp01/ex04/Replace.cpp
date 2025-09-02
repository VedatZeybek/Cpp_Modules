#include "Replace.hpp"

void	replaceStr(std::ifstream& infile, std::ofstream& outfile, const std::string& s1, const std::string& s2)
{
	std::string buffer;
	char c;
	
	while (infile.get(c))
	{
		buffer += c;
		if (buffer.size() >= s1.size())
		{	
			if (buffer.substr(buffer.size() - s1.size()) == s1)
			{
				outfile << buffer.substr(0, buffer.size() - s1.size()) << s2;
				buffer.clear();
			}	
		}
	}
	outfile << buffer;
}