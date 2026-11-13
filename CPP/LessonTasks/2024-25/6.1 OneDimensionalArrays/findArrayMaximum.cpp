#include <iostream>
using namespace std;

int main() {
	int ile, maxValue;

	cout << "Podaj ile elementow chcesz wpisac do tablicy: ";
	cin >> ile;

	int* massiv = new int[ile]; // wiem że tego nie robiliśmy ale jak napisałbym
	// int massiv[ile]; to bym nie działało, ponieważ w c++ długość tablicy musi być wiedzialna na etapie kompilacji
	// jak w c#. W swoich programach ten problem był rozwiązywany ze pomocą konstrukcji new

	for (int i = 0; i < ile; i++) {
		cout << "Podaj element nr " << i + 1 << ": ";
		cin >> massiv[i];
	}

	for (int i = 0; i < ile; i++) {
		if (i == 0) {
			maxValue = massiv[i];
		}
		else if (massiv[i] > maxValue) {
			maxValue = massiv[i];
		}
	}


	cout << "Najwieksza wartosc wystepujaca w tablicy to " << maxValue;


	return 0;
}