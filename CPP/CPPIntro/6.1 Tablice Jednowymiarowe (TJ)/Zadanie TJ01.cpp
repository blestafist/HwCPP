#include <iostream>
using namespace std;

int main() {
	int massiv[10];

	for (int i = 0; i < 10; i++) {
		cout << "Podaj liczbe nr " << i + 1 << ": ";
		cin >> massiv[i];
	}

	cout << endl << endl;

	cout << "Podane liczby: ";
	for (int i = 0; i < 10; i++) {
		cout << massiv[i] << ' ';
	}

	return 0;
}
