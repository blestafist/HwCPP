#include <iostream>

int GCD (int a, int b) {
    return b == 0 ? a : GCD (b, a % b);
}

int GCDIt (int a, int b) {
    while (b > 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }

    return a;
}

int LCD (int a, int b) {
    return (a / GCD (a, b)) * b;
}

int main () {
    std::cout << GCD (12, 18);
}
