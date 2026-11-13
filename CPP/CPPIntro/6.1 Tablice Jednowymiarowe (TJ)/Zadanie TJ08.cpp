#include <iostream>
#include <limits.h>

using namespace std;

int main() {
	int ile, maxValue = INT_MIN, minMaxValue = INT_MIN;

	cout << "Podaj ile elementow chcesz wpisac do tablicy: ";
	cin >> ile;

	int massiv[ile];

	for (int i = 0; i < ile; i++) {
		cout << "Podaj element nr " << i + 1 << ": ";
		cin >> massiv[i];
	}

	for (int i = 0; i < ile; i++) {
		if (massiv[i] > maxValue) {
			maxValue = massiv[i];
		}
	}

	for (int i = 0; i < ile; i++) {

        if (massiv[i] > minMaxValue and massiv[i] != maxValue) {
            minMaxValue = massiv[i];
        }
	}


	cout << "Najwieksza wartosc wystepujaca w tablicy to " << maxValue << endl << endl;
	cout << "Prawie największa wartość to " << minMaxValue;


	return 0;
}
