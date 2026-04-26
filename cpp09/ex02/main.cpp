#include "PMergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		PMergeMe pm;
		pm.parseInput(argc, argv);

		const std::vector<int>& data = pm.getVector();
		for (size_t i = 0; i < data.size(); i++)
			std::cout << data[i] << " ";
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}