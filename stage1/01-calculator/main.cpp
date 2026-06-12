#include <functional>
#include <iostream>
#include <stdexcept>
#include <unordered_map>

int main() {
	std::unordered_map<char, std::function<double(double, double)>> operations =
		{
			{'+', [](double x, double y) { return x + y; }},
			{'-', [](double x, double y) { return x - y; }},
			{'*', [](double x, double y) { return x * y; }},
			{'/',
			 [](double x, double y) {
				 if (y == 0)
					 throw std::runtime_error("Division by Zero!");
				 return x / y;
			 }},
		};

	char choice = 'y';

	while (choice == 'y' || choice == 'Y') {
		std::cout << "-------------CALCULATOR----------------" << std::endl;
		std::cout << "Supported Operations: (+), (-), (*), (/)" << std::endl;
		std::cout << "Enter an expression (e.g. 3 + 5): " << std::endl;
		std::cout << "---------------------------------------" << std::endl;
		double x, y;
		char op;
		std::cin >> x >> op >> y;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Please enter a valid expression (e.g. 2 + 5)"
					  << std::endl;
			continue;
		}

		if (operations.contains(op)) {
			try {
				double result = operations[op](x, y);
				std::cout << "Result: " << result << std::endl;
			} catch (const std::exception &e) {
				std::cerr << "Error: " << e.what() << std::endl;
			}
		} else {
			std::cerr << "Invalid Operator: '" << op << "'." << std::endl;
		}
		std::cout << "Calculate Again? (Y/N): " << std::endl;
		std::cin >> choice;
	}

	return 0;
}
