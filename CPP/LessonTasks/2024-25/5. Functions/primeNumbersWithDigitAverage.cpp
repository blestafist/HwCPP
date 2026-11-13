#include <bits/stdc++.h>
using namespace std;

bool czyp(int l) {
    if (l < 2)
        return false;
    for (int i = 2; i * i <= l; i++) {
        if (l % i == 0)
            return false;
    }

    return true;
}

int sumac(int l) {
    int suma = 0;
    while (l > 0) {
        suma += l % 10;
        l /= 10;
    }

    return suma;
}

int ilecyfr(int l) {
    int ile = 0;
    while (l > 0) {
        ile++;
        l /= 10;
    }

    return ile;
}

int main() {
    int licznik = 0;
    for (int i = 2; i <= 5000 ; i++) {
        if (czyp(i) and sumac(i) % ilecyfr(i) == 0) {
            if (i < 10)
                cout << "   " << i << ' ';
            else if (i < 1000)
                cout << "  " << i << ' ';
            else
                cout << i << ' ';

            licznik++;

            if (licznik == 10) {
                cout << endl;
                licznik = 0;
            }
        }
    }
}
