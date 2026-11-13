#include <iostream>
using namespace std;

bool isDevidable(int num) {
	if (num < 2) {
		return false;
	}

	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	
	return true;
}

bool evenNumber(int num) {
	if (num % 2 == 0) {
		return true;
	}
	return false;
}

bool ifNumCorrect(int num) {
	while (num >= 9) {
		if (evenNumber(num % 10)) {
			return false;
		}
		num /= 10;
	}

	if (evenNumber(num)) {
		return true;
	}
}

int main() {
	for (int i = 10; i <= 1000; i++) {
		if (ifNumCorrect(i)) {
			cout << i << ' ';
		}
	}
}