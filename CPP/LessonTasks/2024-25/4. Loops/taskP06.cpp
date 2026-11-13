#include <iostream>
using namespace std;

int main() {
    int number;

    cout << "Podaj liczbę: ";
    cin >> number;

    if (number < 0) {
        cout << "Podana liczba nie jest naturalną";
    }

    for (int i = 1; i <= number / 2; i++) {
        if (number % i == 0) {
            cout << i << ' ';
        }
    }

    cout << number;

    return 0;
}
