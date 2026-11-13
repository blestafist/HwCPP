#include <iostream>

int PosCount (int num) {
	int pos = 0;
	while (num > 0) {
		pos++;
		num /= 10;
	}

	return pos;
}

int Pow10(int num) {
	int res = 1;
	for (int i = 0; i < num; i++) {
		res *= 10;
	}

	return res;
}

bool IsAutomorph(int num) {
	int square = num * num;
	int pos = PosCount(num);

	if (square % (Pow10(pos)) == num) { return true; }

	return false;
}


int main() {
	int ctr = 0;

	for (int i = 10; i <= 1000; i++) {
		if (IsAutomorph(i)) {
			std::cout << i << '\n';
			ctr++;
		}
	}

	std::cout << "Ilość liczb: " << ctr;

}
