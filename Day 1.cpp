#include <iostream>
#include <fstream>
#include <string>
int main()
{
	std::cout << "Hello, world!\n";
	std::ifstream inputFile("input.txt");

	if (!inputFile.is_open()) {
		std::cout << "Unable to open file.\n";
		return 1;
	}

	std::string line;
	int sum = 0;
	while (std::getline(inputFile, line)) {
		int firstInt = -1;
		int lastInt = -1;
		std::cout << line << "\n";

		for (char c : line) {
			if (std::isdigit(c)) {
				int letter = (int)c - 48;
				if (firstInt < 0) {
					firstInt = letter;
					lastInt = letter;
				}
				else {
					lastInt = (int)c - 48;
				}
			}
		}
		std::cout << firstInt << " " << lastInt << "\n\n";
		sum = sum + 10 * firstInt + lastInt;
		
	}
	inputFile.close();
	std::cout << sum;

	return 0;
}