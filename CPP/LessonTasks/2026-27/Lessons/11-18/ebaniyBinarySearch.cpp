#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> T = { 3, 4, 6, 8, 9 };

int Foo (int p, int k, int e) {
    if (p == k) {
        if (T[p] > e) { return p; }
        else { return p + 1; }
    } else {
        int s = (p + k) / 2;
        if (T[s] > e) { return Foo(p, s, e); }
        else { return Foo(s + 1, k, e); }
    }
}

int main () {
    std::cout << Foo(0, 4, 10) + 1;
    return 0;
}
