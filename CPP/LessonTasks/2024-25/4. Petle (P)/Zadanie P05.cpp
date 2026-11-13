#include <iostream>
using namespace std;

int main() {
    int endR, endL, clipboard;

    cout << "Podaj zakres lewy: ";
    cin >> endL;

    cout << "Podaj zakres prawy: ";
    cin >> endR;

    if (endR < endL) {
        clipboard = endR;
        endR = endL;
        endL = clipboard;
    }

    for (int i = endL; i <= endR; i++) {
        if (i%4 == 3) {
            cout << i << ' ';
        }

    }
    return 0;
}
