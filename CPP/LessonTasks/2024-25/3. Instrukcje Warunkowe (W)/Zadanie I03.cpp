#include <iostream>
using namespace std;

int main() {
    int l1, l2, k1, k2; // deklarowanie zmiennych

    cout << "Podaj pierwszą liczbę: ";
    cin >> l1;    // pierwsza liczba

    cout << "Podaj drugą liczbę: ";
    cin >> l2;     // druga liczba

    k1 = l1;
    k2 = l2;   // stworzenie kopii

    if (k1 < 0) {
        k1 = k1 * -1;    // wartość bezwzględna kopii 1
    }

    if (k2 < 0) {
        k2 = k2 * -1;    // wartość bezwzgędna kopii 2
    }

    if (k1 < k2) {
        cout << l1 << ' ' << l2;    // jeżeli kopia1 < kopii2
    }

    else {
        cout << l2 << ' ' << l1;   // inaczej
    }
}
