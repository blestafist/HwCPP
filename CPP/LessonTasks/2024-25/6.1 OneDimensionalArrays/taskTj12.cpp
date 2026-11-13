#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(NULL));
    int tablica[10];

    for (int i = 0; i < 10; i++) {
        tablica[i] = rand()%101;
        cout << tablica[i] << ' ';
    }

    cout << endl << endl;

    for (int i = 0; i < 4; i++) {
    int clipBoard = tablica[i];
    tablica[i] = tablica[9 - i];
    tablica[9 - i] = clipBoard;
    }

    for (int i = 0; i < 10; i++) {
        cout << tablica[i] << ' ';
    }

    return 0;
}
