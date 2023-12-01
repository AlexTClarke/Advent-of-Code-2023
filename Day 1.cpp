#include <iostream>
#include <fstream>
#include <string>
int main()
{
	std::cout << "Hello, world!";
	std::ifstream inputFile("input.txt");

	if (!inputFile.is_open()) {
		std::cout << "Unable to open file.\n";
		return 1;
	}

	std::string line;
	while (std::getline(inputFile, line)) {
		std::cout << line << '\n';
	}
	inputFile.close();

	return 0;
}