 #include "RPN.hpp"

 #include <cctype>

 RPN::RPN()
 {
 }

 RPN::~RPN()
 {
 }

 RPN::RPN(const RPN &other)
 {
 	(void)other;
 }

 RPN &RPN::operator=(const RPN &other)
 {
 	(void)other;
 	return (*this);
 }

 bool RPN::isOperator(char c)
 {
 	return (c == '+' || c == '-' || c == '*' || c == '/');
 }

 bool RPN::applyOperator(std::vector<int> &stack, char op)
 {
 	if (stack.size() < 2)
 		return (false);

 	int right = stack.back();
 	stack.pop_back();
 	int left = stack.back();
 	stack.pop_back();

 	if (op == '+')
 		stack.push_back(left + right);
 	else if (op == '-')
 		stack.push_back(left - right);
 	else if (op == '*')
 		stack.push_back(left * right);
 	else if (op == '/')
 	{
 		if (right == 0)
 			return (false);
 		stack.push_back(left / right);
 	}
 	return (true);
 }

 bool RPN::calculate(const std::string &expression, int &result)
 {
 	std::vector<int> stack;

 	for (std::string::size_type i = 0; i < expression.size(); ++i)
 	{
 		char current = expression[i];

 		if (current == ' ')
 			continue;

 		if (std::isdigit(static_cast<unsigned char>(current)))
 			stack.push_back(current - '0');
 		else if (isOperator(current))
 		{
 			if (!applyOperator(stack, current))
 				return (false);
 		}
 		else
 			return (false);
 	}

 	if (stack.size() != 1)
 		return (false);

 	result = stack.back();
 	return (true);
 }
