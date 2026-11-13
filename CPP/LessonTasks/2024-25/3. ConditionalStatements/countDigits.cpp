#include <iostream>
using namespace std;

int main() {
    int liczba;

    cout << "Podaj liczbe w zakresie od 1 do 1000000: ";
    cin >> liczba;

    if (liczba > 1000000 or liczba < 0) {
        cout << "Liczba nie mieśći się w podanym zakresie!";
    }

    else if (liczba < 10) {
        cout << "Liczba ma 1 cyfrę";
    }

    else if (liczba < 100) {
        cout << "Liczba ma 2 cyfry";
    }

    else if (liczba < 1000) {
        cout << "Liczba ma 3 cyfry";
    }

    else if (liczba < 10000) {
        cout << "Liczba ma 4 cyfry";
    }

    else if (liczba < 100000) {
        cout << "Liczba ma 5 cyfr";
    }

    else {
        cout << "Liczba ma 6 cyfr";
    }

    return 0;
}
