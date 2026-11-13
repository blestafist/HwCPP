#include <iostream>
using namespace std;


int main() {
    int ile;
    cout << "Podaj liczbę: ";
    cin >> ile;

    for (int i = 1; i <= ile; i++) {
        for (int j = 0; j < i; j++) {
            cout << i;
        }

        cout << ' ';
    }

    return 0;
}
