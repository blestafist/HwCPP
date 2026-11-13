#include <iostream>

int SumDigits(int num) {
    int result = 0;

    while (num > 0) {
        result += num % 10;
        num /= 10;
    }

    return result;
}

int main() {
    size_t ctr = 0;
    for (int i = 0; i <= 10000; ++i) {
        if (i == SumDigits(i * i)) { 
            std::cout << i << '\n';
            ++ctr;
        }
    }

    std::cout << "\nIlość liczb: " << ctr << "\n";

    return 0;
}
