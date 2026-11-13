#include <bits/stdc++.h>
using namespace std;

bool czyp(int l) {
    if (l < 2) {
        return false;
    }

    for (int i = 2; i * i <= l; i++) {
        if (l % i == 0)
            return false;
    }

    return true;
}

int pot (int l, int w) {
    int p = 1;
    for (int i = 0; i < w; i++) {
        p *= l;
    }

    return p;
}

int sc(int l) {
    int suma = 0;
    while (l > 0) {
        suma += l % 10;
        l /= 10;
    }

    return suma;
}

int ilecyfr (int l) {
    int ile = 0;
    while (l > 0) {
        ile++;
        l /= 10;
    }
    return ile;
}

int main() {
    for (int i = 2; i <= 10000; i++) {
        if (czyp(i) and sc(i) == pot(2, ilecyfr(i)))
            cout << i << ' ';
    }
}
