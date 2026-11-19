#include <iostream>


constexpr int T[] { 0, 1, 3, 10, 10, 18 };


int F (int p, int k, int e) {   
    if (k == p) {
        if (T[p] > e) {
            return p;
        } else {
            return p + 1;
        }
    }
    else {
        int s = (p + k) / 2;
        if (T[s] > e) {
            return F(p, s, e);
        }
        else {
            return F(s + 1, k, e);
        }
    }

}


int main() {
    int p = 1;
    int k = 5;
    int e = 10;

    std::cout << F(p, k, e);

    return 0;
}

// 24.1 - 6, 1, 3, 5
// 24.2 - dziel i zwyciezaj
// 24.3 - log2 n
