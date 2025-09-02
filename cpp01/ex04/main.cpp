#include "Replace.hpp"

int main(int ac, char **argv)
{
	if (ac != 4)
	{
		std::cerr << "Error: Argument Count is not appropriate.\n";
		return (1);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];


	if (s1.empty())
	{
        std::cerr << "Error: s1 is empty.\n";
        return (1);
    }

	std::ifstream infile(filename.c_str());
	if (!infile)
	{
		std::cerr << "Error: couldn't open file " << filename << "\n";
		return (1);
    }

	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile)
	{
		std::cerr << "Error: couldn't create file " << filename << ".replace\n";
		return (1);
	}

	replaceStr(infile, outfile, s1, s2);
}
