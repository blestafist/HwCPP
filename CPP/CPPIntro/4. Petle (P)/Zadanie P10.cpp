#include <iostream>
using namespace std;

int main() {
    int liczba;
    bool isFirst = true;

    cout << "Wprowadż liczbę: ";
    cin >> liczba;

    for (int i = 2; i * i <=
     liczba; i++) {
        if (liczba % i == 0) {
            cout << "To jest liczba złożona";
            isFirst = false;
            break;
        }
    }

    if (isFirst == true) {
        cout << "To jest liczba pierwsza";
    }

    return 0;
}
