#include <iostream>
using namespace std;

int main() {
    int pocz, krok, ile;

    cout << "Podaj liczbę początkową: ";
    cin >> pocz;
    cout << endl;

    cout << "Podaj krok: ";
    cin >> krok;
    cout << endl;

    cout << "Podaj ilość elementów: ";
    cin >> ile;
    cout << endl << endl;

    cout << "Zgenerowany ciąg arytmetyczny: ";


    for (int i = 0; i < ile; i++) {
        cout << pocz << ", ";
        pocz += krok;
    }

    cout << endl << endl << endl;

    return 0;
}
