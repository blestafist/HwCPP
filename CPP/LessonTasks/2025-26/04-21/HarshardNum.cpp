#include <iostream>

int SumDigits(int num) {
	int result = 0;
	while (num > 0) {
		result += num % 10;
		num /= 10;
	}

	return result;
}

int main() {
	size_t ctr = 0;

	for (int i = 10; i <= 1000; i++) {
		if (i % SumDigits(i) == 0) {
			std::cout << i << '\n';
			ctr++;
		}
	}

	std::cout << "Liczb Harsharda: " << ctr << '\n';

	return 0;
}
