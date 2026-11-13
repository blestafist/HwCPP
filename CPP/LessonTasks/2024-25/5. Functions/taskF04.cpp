#include <bits/stdc++.h>
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

bool czyr(int l) {
    int ost = 10;
    while (l > 0) {
        if (l%10 >= ost) {
            return false;
        }
        ost = l % 10;
        l /= 10;
    }

    return true;
}

int main() {
    for (int i = 100; i <= 1000; i++) {
        if (czyp(i) and czyr(i)) {
            cout << i << ' ';
        }
    }

    return 0;
}
