#include <iostream>
#include <chrono>
#include <iomanip>


bool IsPrimeV1(unsigned long long num) {
    if ( num < 2 ) { return false; }

    for (unsigned long long i = 2; i * i <= num; i++) {
        if (num % i == 0) { return false; }
    }

    return true;
}


bool IsPrimeV2(unsigned long long num) {
    if (num < 2) { return false; }
    if (num == 2 || num == 3) { return true; }
    if (num % 2 == 0 || num % 3 == 0) { return false; }

    for (unsigned long long i = 5; i * i <= num; i += 6) { 
        if (num % i == 0 || num % (i + 2) == 0) { return false; }
    }
    
    return true;
}

int main() {
    unsigned long long startNum = 100000000; 
    int range = 100000;

    std::cout << "Benchmarking range of " << range << " numbers...\n";
    std::cout << "Starting from: " << startNum << "\n\n";

    // Test V1
    auto s1 = std::chrono::high_resolution_clock::now();
    for (unsigned long long i = startNum; i < startNum + range; i++) {
        IsPrimeV1(i);
    }
    auto e1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> t1 = e1 - s1;

    // Test V2
    auto s2 = std::chrono::high_resolution_clock::now();
    for (unsigned long long i = startNum; i < startNum + range; i++) {
        IsPrimeV2(i);
    }
    auto e2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> t2 = e2 - s2;

    // Results
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Total time V1: " << t1.count() << "s\n";
    std::cout << "Total time V2: " << t2.count() << "s\n";

    if (t2.count() > 0) {
        std::cout << "\nV2 is " << t1.count() / t2.count() << "x faster than V1\n";
    }

    return 0;
}
