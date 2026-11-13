#include <iostream>
using namespace std;

int main() {
    int ile, el1 = 1, el2 = 1;

    cout << "Podaj ilość elementów: ";
    cin >> ile;

    for (int i = 0; i < ile; i++) {
        cout << el2 << ' ';
        if (i > 0) {
            el2 = el1 + el2;
            el1 = el2 - el1;
        }
    }

    return 0;
}
