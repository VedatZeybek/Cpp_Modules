#include "PMergeMe.hpp"
#include <ctime>
#include <deque>
#include <iomanip>

int main(int argc, char **argv)
{
	try
	{
		PMergeMe pm;
		pm.parseInput(argc, argv);

		const std::list<int>& data = pm.getList();
		std::cout << "Before: ";
		for (std::list<int>::const_iterator it = data.begin(); it != data.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		// Sort with std::list
		std::list<int> lst(data.begin(), data.end());
		clock_t start = clock();
		std::list<int> sortedList = pm.fordJohnsonList(lst);
		clock_t end = clock();
		double timeListUs = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

		std::cout << "After: ";
		for (std::list<int>::const_iterator it = sortedList.begin(); it != sortedList.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		// Sort with std::deque
		std::deque<int> deq(data.begin(), data.end());
		start = clock();
		std::deque<int> sortedDeq = pm.fordJohnsonDeque(deq);
		end = clock();
		double timeDeqUs = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

		std::cout << std::fixed << std::setprecision(5);
		std::cout << "Time to process a range of " << std::distance(data.begin(), data.end())
			  << " elements with std::list : " << timeListUs << " us" << std::endl;
		std::cout << "Time to process a range of " << std::distance(data.begin(), data.end())
			  << " elements with std::deque : " << timeDeqUs << " us" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}