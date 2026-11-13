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

int ile(int l, int c) {
    int ilerazy = 0;
    while (l > 0) {
        if (l % 10 == c) {
            ilerazy++;
        }
        l /= 10;
    }

    return ilerazy;
}

int main() {
    for (int i = 0; i < 10; i++) {
        int ilerazy = 0;
        for (int j = 2; j <= 1000; j++) {
            if (czyp(j)) {
                ilerazy += ile(j, i);
            }
        }

        cout << "Cyfra " << i << " występuje razy: " << ilerazy << endl;
    }

    return 0;
}

