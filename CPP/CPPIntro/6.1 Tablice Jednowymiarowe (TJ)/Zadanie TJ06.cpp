#include <iostream>
using namespace std;

int main() {
    int ile;
    cout << "Podaj ilość elementów: ";
    cin >> ile;

    int tablica[ile];

    for(int i = 0; i < ile; i++) {
        cout << "Podaj element nr " << i + 1 << ": ";
        cin >> tablica[i];
    }

    for(int i = 0; i < ile; i++) {
        if (tablica[i] % 3 == 0 and i % 2 == 0) {
            cout << tablica[i] << ' ';
        }
    }

    return 0;
}

