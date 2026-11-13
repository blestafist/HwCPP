#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(NULL));
    int tablica1[10], tablica2[10], tablica3[20];

    for (int i = 0; i < 10; i++) {
        tablica1[i]=rand() % 100 + 100;
        tablica2[i] = rand() % 100 + 200;
    }

    for (int i = 0; i < 10; i++) {
        cout << tablica2[i] << ' ';
    }

    cout << endl;


    for (int i = 0; i < 10; i++) {
        cout << tablica1[i] << ' ';
    }

    for (int i = 0; i < 20; i+=2) {
        int j = i / 2;
        tablica3[i] = tablica1[j];
        tablica3[i + 1] = tablica2[j];
    }


    cout << endl << endl << "Wszystkie elementy tablicy 3: " << endl << endl;

    for (int i : tablica3) {
        cout << i << ' ';
        if (i == tablica3[9]) {
            cout << endl;
        }
    }

    return 0;
}

