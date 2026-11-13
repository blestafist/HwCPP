#include <bits/stdc++.h>
#include <limits.h>

using namespace std;

int main() {
    srand(time(NULL));
    int tablica[10]{}, maks = INT_MIN;

    for (int i = 0; i < 100; i++) {
        tablica[rand()%10]++;
    }

    cout << "Liczby:           ";

    for(int i = 0; i < 10; i++) {
        if (tablica[i] > 9)
            cout << ' ';

        cout << i << ' ';
    }

    cout << endl << "Liczba wylosowań: ";

    for (int i = 0; i < 10; i++) {
        cout << tablica[i] << ' ';
    }

    for (int i = 0; i < 10; i++) {
        if (tablica[i] > maks) {
            maks = tablica[i];
        }
    }

    cout << endl << endl;

    for (int i = 0; i < 10; i++) {
        if (tablica[i] == maks) {
            cout << "Liczba " << i << " została wylosowana " << maks << " razy" << endl;
        }
    }

    return 0;
}


