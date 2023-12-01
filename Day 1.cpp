#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
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
	std::map<std::string, char> m;
	m["one"] = '1';
	m["two"] = '2';
	m["three"] = '3';
	m["four"] = '4';
	m["five"] = '5';
	m["six"] = '6';
	m["seven"] = '7';
	m["eight"] = '8';
	m["nine"] = '9';
	std::cout << m["nine"] << "\n";

	while (std::getline(inputFile, line)) {
		int firstInt = -1;
		int lastInt = -1;
		std::cout << line << "\n";
		std::string threelen = "";
		std::string fourlen = "";
		std::string fivelen = "";
		for (char c : line) {
			threelen += c;
			fourlen += c;
			fivelen += c;
			if (threelen.length() > 3) {
				threelen = threelen.substr(1, threelen.length());
			}
			if (fourlen.length() > 4) {
				fourlen = fourlen.substr(1, fourlen.length());
			}
			if (fivelen.length() > 5) {
				fivelen = fivelen.substr(1, fivelen.length());
			}
			if (fivelen.length() == 5) {
				if (m.find(fivelen) != m.end()) {
					c = m[fivelen];
					std::cout << "Found a " << c << "\n";
				}
			}
			if (fourlen.length() == 4) {
				if (m.find(fourlen) != m.end()) {
					c = m[fourlen];
					std::cout << "Found a " << c << "\n";
				}
			}
			if (threelen.length() == 3) {
				if (m.find(threelen) != m.end()) {
					c = m[threelen];
					std::cout << "Found a " << c << "\n";
				}
			}
			std::cout << threelen << " " << fourlen << " " << fivelen << " " << c << "\n";

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