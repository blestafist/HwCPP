#include <iostream>

unsigned long long IntPower(int base, int exponent) {
    if (exponent == 0) { return 1; }
    else if (base == 0) { return 0; }
    unsigned long long result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}

int NumOfPlaces(unsigned long long num) {
    if (num == 0) { return 1; }
    int result = 0;

    while (num > 0) {
        result++;
        num /= 10;
    }

    return result;
}

bool IsArmstrong(unsigned long long num) {
    if (num == 0) { return true; }

    int numOfPlaces = NumOfPlaces(num);
    unsigned long long sum = 0, cp = num;

    while (cp > 0) {
        sum += IntPower((cp % 10), numOfPlaces);
        cp /= 10;

        if (sum > num) { return false; }
    }

    return sum == num;
}

int main() {
    int ctr = 0;
    for (int i = 10; i <= 1000; i++) {
        if (IsArmstrong(i)) { std::cout << i << '\n'; ctr++; }
    }

    std::cout << "Ilość liczb: " << ctr;

    return 0;
}
