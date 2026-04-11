#include <iostream>
#include <stack>
#include <vector>
#include <cstring>

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	std::vector<int>	s;
	int					result = 0;
	int 				temp = 0;
	int 				divider = 0;
	int					i = 0;
	const char			*str = argv[1];

	while (str[i] != '\0')
	{
		temp = 0;
		while (str[i] == ' ')
			i++;
		if (isdigit(str[i]))
		{
			s.push_back((str[i] - '0'));
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			if (s.size() >=  2 && str[i] == '+')
			{
				temp += (s[s.size() - 1]);
				s.pop_back();
				temp += (s[s.size() - 1]);
				s.pop_back();
				s.push_back((temp));
			}
			else if (s.size() >=  2 && str[i] == '-')
			{
				temp -= (s[s.size() - 1]);
				s.pop_back();
				temp += (s[s.size() - 1]);
				s.pop_back();
				s.push_back((temp));
			}
			else if (s.size() >=  2 && str[i] == '*')
			{
				temp += (s[s.size() - 1]);
				s.pop_back();
				temp *= (s[s.size() - 1]);
				s.pop_back();
				s.push_back((temp));
	
			}
			else if (s.size() >=  2 && str[i] == '/')
			{
				divider = (s[s.size() - 1]);
				if (divider == 0)
				{
					std::cerr << "Error" << std::endl;
					return (1);
				}
				s.pop_back();
				temp += (s[s.size() - 1]);
				s.pop_back();
				temp = temp / divider;
				s.push_back((temp));
			}
			else
				std::cerr << "Error" << std::endl;
				return (1);
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return (1);
		}
		i++;
	}
	if (s.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	result = (s[s.size() - 1]);
	std::cout << result << std::endl;
	
	return 0;
}
