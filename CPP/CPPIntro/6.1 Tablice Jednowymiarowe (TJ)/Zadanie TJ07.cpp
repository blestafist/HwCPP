#include <iostream>
using namespace std;

int main() {
    int ile, maks, licznik = 0;
    cout << "Podaj ilość elementów: ";
    cin >> ile;

    int tablica[ile];

    for(int i = 0; i < ile; i++) {
        cout << "Podaj element nr " << i + 1 << ": ";
        cin >> tablica[i];
    }

    maks = tablica[0];

    for(int i = 1; i < ile; i++) {
        if (tablica[i] > maks) {
            maks = tablica[i];
        }
    }

    for(int i = 0; i < ile; i++) {
        if (tablica[i] == maks) {
            licznik++;
        }
    }


    cout << endl << endl << "Maksymalna wartość: " << maks << endl << endl;;

    cout << "Maksymalna wartość wystąpiła " << licznik << " razy." << endl << endl;

    return 0;
}


