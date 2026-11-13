#include <iostream>
using namespace std;

int main() {
    int liczba, suma = 0;

    do {
        cout << "Podaj liczbę: ";
        cin >> liczba;

        suma += liczba;
    } while (liczba != 0);

    cout << "Suma podanych liczb: " << suma;

    return 0;
}
