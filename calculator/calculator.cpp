#include <iostream>
#include <sstream>
#include <vector>

int main()
{
	std::cout << "Welcome to the calculator.\n"
		<< "The following operations (and format) are permitted:\n"
		<< "X + Y\n"
		<< "X - Y\n"
		<< "X * Y\n"
		<< "X / Y\n";

	std::string input = "";

	while (std::getline(std::cin, input))
	{
		if (input == "exit")
		{
			return 0;
		}

		std::vector<std::string> parts;
		std::string outstring;
		std::string delimiter = " ";

		size_t pos = 0;
		while ((pos = input.find(delimiter)) != std::string::npos)
		{
			outstring = input.substr(0, pos);
			parts.push_back(outstring);
			input.erase(0, pos + 1);
		}

		// Pusing the last bit of input that is left to parts.
		parts.push_back(input);

		if (parts.size() != 3)
		{
			std::cout << "Incorrect number of inputs. Try again.\n";
			continue;
		}

		double first, second;

		try
		{
			first = stod(parts[0]);
		}
		catch (std::exception _)
		{
			std::cout << "Incorrect format. First input was :" << parts[0] << "\n";
			continue;
		}

		try
		{
			second = stod(parts[2]);
		}
		catch (std::exception _)
		{
			std::cout << "Incorrect format. Second input was :" << parts[2] << "\n";
			continue;
		}

		std::string op = parts[1];
		switch (op[0])
		{
		case '+':
			std::cout << "Answer: " << first + second << "\n";
			break;
		case '-':
			std::cout << "Answer: " << first - second << "\n";
			break;
		case '*':
			std::cout << "Answer: " << first * second << "\n";
			break;
		case '/':
			std::cout << "Answer: " << first / second << "\n";
			break;
		default:
			std::cout << "Invalid operation. Operation input was: " << op[0] << "\n";
			break;
		}
	}
}