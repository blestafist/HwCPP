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

bool czyl(int l) {
    while (l > 0) {
        if (l%10 != 3 and l%10 != 7) {
            return false;
        }
        l/=10;
    }

    return true;
}

int main() {
    for (int i = 2; i <= 1000; i++) {
        if (czyp(i) and czyl(i)) {
            cout << i << ' ';
        }
    }

    return 0;
}
