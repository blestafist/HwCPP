#include <iostream>
using namespace std;

int main() {
    int liczba, nowa = 1;

    cout << "Podaj liczbę: ";
    cin >> liczba;

    while (liczba > 9) {
        cout << liczba << ' ';
        while (liczba > 0) {
            nowa *= liczba%10;
            liczba /= 10;
        }
        liczba = nowa;
        nowa = 1;
    }

    cout << liczba;

    return 0;

}

