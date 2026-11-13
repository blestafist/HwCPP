#include <cstdlib>
#include <iostream>


int CountDigits(int num) {
    if (num == 0) { return 1; }
    int counter = 0;
    while (num > 0) {
        ++counter;
        num /= 10;
    }
    return counter;
}


int Power(int base, int exponent) {
    if (exponent == 0) { return 1; }
    int result = base;
    for (int i = 0; i < exponent - 1; ++i) {
        result *= base;
    }
    return result;
}


bool IsArmstrong(int num, size_t size) {
    int original = num;
    int sum = 0;
    while (num > 0) {
        sum += Power(num % 10, size);
        num /= 10;
    }
    return sum == original;
}


int main() {
    int counter = 0;
    for (int i = 10; i <= 1000; ++i) {
        if (IsArmstrong(i, CountDigits(i))) {
            std::cout << i << '\n';
            ++counter; 
        }
    }
    std::cout << "\nIlość liczb: " << counter;
    return 0;
}