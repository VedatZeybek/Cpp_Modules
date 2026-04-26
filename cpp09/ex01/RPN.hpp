 #ifndef RPN_HPP
 #define RPN_HPP

 #include <string>
 #include <vector>

 class RPN
 {
 	public:
 		static bool calculate(const std::string &expression, int &result);

 	private:
 		RPN();
 		~RPN();
 		RPN(const RPN &other);
 		RPN &operator=(const RPN &other);

 		static bool isOperator(char c);
 		static bool applyOperator(std::vector<int> &stack, char op);
 };

 #endif
