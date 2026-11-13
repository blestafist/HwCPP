#include <iostream>
using namespace std;

bool czyp(int l) {
    if (l < 2) {
        return false;
    }

    for (int i = 2; i * i <= l; i++) {
        if (l % i == 0) {
            return false;
        }
    }

    return true;
}

bool czyzawieraxy(int l, int x, int y) {
    int ilerazy = 0;
    while (l > 0) {
        if (l % 10 == y) {
            ilerazy++;
        }
        l /= 10;
    }

    if (ilerazy == x)
        return true;
    return false;

}

bool czyzawieraz(int l, int z) {
    while (l > 0) {
        if (l % 10 == z) {
            return true;
        }
        l /= 10;
    }

    return false;
}

int main() {
    int x, y, z;
    cout << "Podaj szukana cyfre: ";
    cin >> x;
    cout << "Podaj ile razy ona ma wystapic: ";
    cin >> y;
    cout << "Podaj jakiej cyfry ma nie byc: ";
    cin >> z;

    for (int i = 2; i <= 10000; i++) {
        if (czyp(i) and !czyzawieraz(i, z) and czyzawieraxy(i, x, y))
            cout << i << ' ';
    }

    return 0;
}

