#include <iostream>

int powers[10] {};

unsigned long long IntPower(int base, int exponent) {
    if (exponent == 0) { return 1; }
    else if (base == 0) { return 0; }
    unsigned long long result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}

bool IsMuchausen(unsigned long long num) {
    if (num == 0) { return false; }
    unsigned long long sum = 0, cp = num;

    while (cp > 0) {
        sum += powers[cp % 10];
        cp /= 10;
    }

    return sum == num;
}

int main() {

    for (int i = 0; i < 10; i++) {
        powers[i] = IntPower(i, i);
        //std::cout << i << ' ' << powers[i] << '\n';
    }

    powers[0] = 0; // comment / uncomment this line to follow / not follow the OEIS rules
    int ctr = 0;

    for (int i = 10; i <= 1000; i++) {
        if (IsMuchausen(i)) { std::cout << i << "\n"; ctr++; }
    }

    std::cout << "Ilość liczb: " << ctr;

    return 0;
}
