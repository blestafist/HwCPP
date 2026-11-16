#include <iostream>
#include <vector>

std::vector<unsigned long long> Dividers (unsigned long long num) {
    std::vector<unsigned long long> result = { 1 };
    unsigned long long lim = 2;
    
    for (unsigned long long i = 2; i <= num / lim; ++i) {
        if (num % i == 0) {
            result.push_back(i);
        } 
    }

    return result;
}


unsigned long long SumArr (const std::vector<unsigned long long>& arr) {
    unsigned long long result = 0;
    for (auto i : arr) {
        result += i;
    }

    return result;
}


int main () {
    unsigned long long num;
    
    std::cout << "Wprowadz liczbe: ";
    std::cin >> num;

    std::vector<unsigned long long> dividers = Dividers(num);

    for (auto i : dividers) {
        std::cout << i << ' ';
    }

    std::cout << "\n";
    
    unsigned long long sum = SumArr(dividers);

    std::cout << sum << "\n";

    bool result = sum == num;
    if (result) {
        std::cout << "Liczba " << num << " jest liczba doskonala";
    } else {
        std::cout << "Liczba " << num << " nie jest liczba doskonala";
    }
}
