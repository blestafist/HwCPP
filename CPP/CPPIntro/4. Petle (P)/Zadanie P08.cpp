#include <iostream>
using namespace std;

int main() {
    int liczba, sumaC = 0, ilC = 1;

    cout << "Podaj liczbę: ";
    cin >> liczba;

    while (liczba > 0) {
        sumaC += liczba%10;
        ilC *= liczba%10;

        liczba /= 10;
    }

    cout << "Suma cyfr tej liczby jest równa: " << sumaC << endl;
    cout << "Iloczyn cyfr tej liczby jest równy: " << ilC;

    return 0;
}
