#include <iostream>


int DigitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}


int main() {
    int count = 0;
    for (int i = 10; i <= 100; ++i) {
        if (i % DigitSum(i) == 0) { ++count; }
    }
    std::cout << count;
    return 0;
}