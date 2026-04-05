#include "iostream"
#include <stack>
#include <vector>
#include "cstring"

int main(int argc, char const *argv[])
{
	std::vector<std::string> s;
	int		result = 0;
	int 	temp = 0;
	if (argc != 2)
		return (1);
	int	i = 0;
	char *str = new char[100];
	std::strcpy(str, argv[1]);
	while (str[i] != '\0')
	{
		temp = 0;
		while (str[i] == ' ')
			i++;
		if (isdigit(str[i]))
		{
			s.push_back(std::string() + str[i]);
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			if (s.size() >=  2 && str[i] == '+')
			{
				temp += std::stoi(s[s.size() - 1]);
				s.pop_back();
				temp += std::stoi(s[s.size() - 1]);
				s.pop_back();
				s.push_back(std::to_string(temp));
			}
			else
				return (1);
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			if (s.size() >=  2 && str[i] == '-')
			{
				temp += std::stoi(s[s.size() - 1]);
				s.pop_back();
				temp -= std::stoi(s[s.size() - 1]);
				s.pop_back();
			}
			else
				return (1);
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			if (s.size() >=  2 && str[i] == '*')
			{
				temp += std::stoi(s[s.size() - 1]);
				s.pop_back();
				temp *= std::stoi(s[s.size() - 1]);
				s.pop_back();
				s.push_back(std::to_string(temp));

			}
			else
				return (1);
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			if (s.size() >=  2 && str[i] == '/')
			{
				temp += std::stoi(s[s.size() - 1]);
				s.pop_back();
				temp /= std::stoi(s[s.size() - 1]);
				s.pop_back();
				s.push_back(std::to_string(temp));
			}
			else
				return (1);
		}
		else if (str[i] == '\0')
			break;
		else
		{
			std::cout << "why mr anderson why?" << std::endl;
			return (1);
		}
		i++;
	}

	result = std::stoi(s[s.size() - 1]);

	std::cout << result << std::endl;
	
	delete str;
	return 0;
}
