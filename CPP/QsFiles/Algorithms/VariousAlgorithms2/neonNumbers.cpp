#include <iostream>


int DigitsSum(unsigned long long num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}


bool IsNeon(int num) {
    const unsigned long long square = static_cast<unsigned long long>(num) * num;
    return DigitsSum(square) == num;
}


int main() {
    int counter = 0;
    for (int i = 0; i < 10000; ++i) {
        if (IsNeon(i)) {
            std::cout << i << ' ';
            ++counter;
        }
    }
    std::cout << "\nIlość tych liczb: " << counter;
    return 0;
}