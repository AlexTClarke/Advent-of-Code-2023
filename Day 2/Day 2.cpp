// Day 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>


int main()
{
    std::cout << "Hello World!\n";
	std::ifstream inputFile("input.txt");
	int maxRed = 12;
	int maxGreen = 13;
	int maxBlue = 14;
	int sum = 0;

	if (!inputFile.is_open()) {
		std::cout << "Unable to open file.\n";
		return 1;
	}
	std::string line;
	int gameID = 0;
	while (std::getline(inputFile, line)) {
		gameID++;
		int curRed = 0;
		int curGreen = 0;
		int curBlue = 0;
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == ':') {
				line = line.substr(i + 2, line.length());
				break;
			}
		}
		std::vector<int> nums;
		int num = 0;
		std::cout << line << "\n";
		for (int i = 0; i < line.length(); i++) {
			if (std::isdigit(line[i])) {
				nums.push_back((int)line[i] - 48);

				if (!(std::isdigit(line[i + 1]))) {
					for (int i = nums.size()-1; i >= 0; i--) {
						num += nums[i] * pow(10, (nums.size() - (i + 1)));
					}
					if (line.substr(i + 2, 3) == "red") {
						if (num > curRed){
							curRed = num;
						}
						std::cout << "Found " << num << " Reds\n";
						num = 0;
						nums = {};
					}
					else if ((line.substr(i + 2, 4) == "blue")) {
						if (num > curBlue) {
							curBlue = num;
						}
						std::cout << "Found " << num << " Blues\n";
						num = 0;
						nums = {};
					}
					else if ((line.substr(i + 2, 5) == "green")) {
						if (num > curGreen) {
							curGreen = num;
						}
						std::cout << "Found " << num << " Greens\n";
						num = 0;
						nums = {};
					}
				}

			}

		}
		//std::cout << curRed << " Reds " << curGreen << " Greens " << curBlue << " Blues";
		//std::cout << "\n\n\n\n\n";
		if (curRed <= maxRed && curGreen <= maxGreen && curBlue <= maxBlue) {
			sum += gameID;
		}

	}
	std::cout << sum << "\n";
}