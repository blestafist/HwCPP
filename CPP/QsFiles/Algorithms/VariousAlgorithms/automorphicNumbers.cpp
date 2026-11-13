#include <iostream>


bool IsAutomorphic(int num) {
    long long squaredValue = static_cast<long long>(num) * num;
    while (num > 0) {
        if (num % 10 != squaredValue % 10) { return false; }
        num /= 10;
        squaredValue /= 10;
    }
    return true;
}


int main() {
    int counter = 0;
    for (int i = 10; i <= 100; ++i) {
        if (IsAutomorphic(i)) {
            std::cout << i << '\n';
            ++counter;
        }
    }
    std::cout << "\nIlość liczb: " << counter;
    return 0;
}