#include <iostream>
using namespace std;

int main() {
    int l1, l2;

    cout << "Podaj pierwszą liczbę: ";
    cin >> l1;

    cout << "Podaj drugą liczbę: ";
    cin >> l2;

    while (l1 != l2) {

        if (l1 > l2) {
            l1 -= l2;
        }

        else {
            l2 -= l1;
        }

    }

    cout << "NWD: " << l1;
}
