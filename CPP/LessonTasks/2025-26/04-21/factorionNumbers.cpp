#include <iostream>

unsigned long long factorials[10] {};

unsigned long long Factorial(int base) {
    unsigned long long result = 1;
    for (int i = 1; i <= base; i++) {
        result *= i;
    }

    return result;
}

bool IsFactorion(unsigned long long num) {
    if (num == 0) { return false; } // because 0! == 1
    unsigned long long sum = 0, cp = num;

    while (cp > 0) {
        sum += factorials[cp % 10];
        cp /= 10;
    }

    return sum == num;
}

int main() {
    for (int i = 0; i < 10; i++) { // precompuiting
        factorials[i] = Factorial(i);
    }

    int ctr = 0;

    for (int i = 10; i <= 1000; i++) {
        if (IsFactorion(i)) {
            std::cout << i << '\n';
            ctr++;
        }
    }

    std::cout << "Ilość liczb: " << ctr;
    return 0;
}
