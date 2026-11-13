#include <iostream>
using namespace std;

int main() {
    float l1, l2;   // deklarowanie zmiennych
    char znak;

    cout << "Podaj pierwszą liczbę: ";
    cin >> l1;

    cout << "Podaj działanie: ";
    cin >> znak;

    cout << "Podaj drugą liczbę: ";
    cin >> l2;

    if (znak == '+') {   // dodawanie
        cout << "Wynik działania " << l1 << " " << znak << " " << l2 << " = " << l1 + l2;
    }

    else if (znak == '-') {  // odejmowanie
        cout << "Wynik działania " << l1 << " " << znak << " " << l2 << " = " << l1 - l2;
    }

    else if (znak == '*') {   // mnozenie
        cout << "Wynik działania " << l1 << " " << znak << " " << l2 << " = " << l1 * l2;
    }

    else if (znak == '/') { // dzielenie
        if (l2 == 0) {
            cout << "Nie można dzielić przez zero!";
        }
        else {
            cout << "Wynik działania " << l1 << " " << znak << " " << l2 << " = " << l1 / l2;
        }
    }

    else {  // nieprawidlowy znak
        cout << "Nieprawidlowy znak!";
    }
}
