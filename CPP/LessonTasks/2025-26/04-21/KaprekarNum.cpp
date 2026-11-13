#include <iostream>
#include <string>
#include <algorithm>

std::string IntToStr(int num) {
	std::string result = "";

	while (num > 0) {
		result += (num % 10) + '0';
		num /= 10;
	}

	std::reverse(result.begin(), result.end());
	return result;
}

int StringToInt(const std::string& str) {
	int result = 0;
	for (char c : str) {
		result *= 10;
		result += c - '0';
	}

	return result;
}

bool IsKaprekar(int num) {
	int square = num * num;

	std::string sqStr = IntToStr(square);

	for (int i = 1; i < sqStr.size(); i++) {
		std::string first = sqStr.substr(0, i);
		std::string second = sqStr.substr(i, sqStr.size() - 1);

		int firstInt = StringToInt(first);
		int secondInt = StringToInt(second);

		if (firstInt + secondInt == num) { return true; }
	}

	return false;
}


int main() {
	int ctr = 0;

	for (int i = 10; i <= 1000; i++) {
		if (IsKaprekar(i)) {
			std::cout << i << '\n';
			ctr++;
		}
	}

	std::cout << "Ilość liczb: " << ctr;
}
