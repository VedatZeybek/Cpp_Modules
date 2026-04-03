#include "iostream"
#include <stack>
#include <vector>
#include "cstring"

int main(int argc, char const *argv[])
{
	std::stack<int> s;
	std::vector<int> v;

	if (argc != 2)
		return (1);
	int	i = 0;
	char *str = new char[100];
	std::strcpy(str, argv[1]);
	while (argv[1][i] != '\0')
	{
		while (argv[1][i] == ' ')
			i++;
		if (isdigit(argv[1][i]))
			s.push(atoi(argv[i]));
		if (argv[1][i] == '+' || argv[1][i] == '-')
			//s.push(atoi(argv[i]));
		i++;
	}
	return 0;
}
