#include <iostream>
#include <vector>


std::vector<long long> FindPrimeFactors(long long num) {
    std::vector<long long> factors;

    for (long long divisor = 2; divisor * divisor <= num; ++divisor) {
        while (num % divisor == 0) {
            factors.push_back(divisor);
            num /= divisor;
        }
    }
    if (num > 1) {
        factors.push_back(num);
    }

    return factors;
}


int main() {
    long long num = 100; // Enter your number here
    if (num < 2) {
        std::cout << "brak rozkladu na czynniki pierwsze";
        return 0;
    }

    auto factors = FindPrimeFactors(num);

    std::cout << "rozklad liczby " << num << " na czynniki pierwsze: ";
    for (size_t i = 0; i < factors.size(); ++i) {
        std::cout << factors[i] << (i + 1 < factors.size() ? " * " : "\n");
    }

    return 0;
}
