#include <bits/stdc++.h>
using namespace std;

int ileZl (int num) {
    int licznik = 0, k;
    bool isLast3 = false;
    for (int i = 13; i <= num; i++) {
        k = i;
        while (k > 0) {
            if (k % 10 == 3) {
                isLast3 = true;
                k /= 10;
                continue;
            }

            if (isLast3 and k % 10 == 1) {
                licznik += 2;
                isLast3 = false;
            }

            if (isLast3 and k % 10 != 3) {isLast3 = false;}

            k /= 10;

        }
    }

    return licznik - 2;
}


int main() {
    int ile;
    cout << "Podaj ile stron: ";
    cin >> ile;

    cout << ileZl(ile);
}
