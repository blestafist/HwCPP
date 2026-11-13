#include <iostream>
using namespace std;

int main() {
    int ile, el=2;
    cout << "Podaj ilość elementów";
    cin >> ile;

    for (int i = 2; i <= ile + 1; i++) {
        cout << el << ' ';
        if (i % 2 == 0) {
            el += (i / 2);
        }
        else {
            el *= (i / 2);
        }
    }

    return 0;

}
