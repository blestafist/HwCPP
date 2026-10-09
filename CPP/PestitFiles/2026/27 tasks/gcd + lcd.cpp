#include <iostream>

int gcd (int a, int b) {
    return b == 0 ? a : gcd (b, a % b);
}

int gcd_it (int a, int b) {
    while (b > 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }

    return a;
}

int lcd (int a, int b) {
    return (a / gcd (a, b)) * b;
}

int main () {
    std::cout << lcd (12, 18);
}
