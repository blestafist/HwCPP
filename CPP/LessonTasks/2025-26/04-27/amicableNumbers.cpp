#include <iostream>

// =========================== CONFIGURATION ===========================

const int MIN = 100;
const int MAX = 10000;

// =====================================================================

int SumDividers(int num) {
    int result = 0;
    for (int i = 1; i <= num / 2; ++i) {
        if (num % i == 0) { result += i; }
    }

    return result;
}


int main() {
    size_t ctr = 0;

    // precomputing 
    int computed[MAX + 1];
    for (size_t i = MIN; i < MAX + 1; ++i) {
        computed[i] = SumDividers(i);
    }

    for (int i = 100; i <= 10000; ++i) {
        for (int j = i + 1; j <= 10000; ++j) {
            if (computed[i] == j && computed[j] == i) {
                std::cout << i << ' ' << j << '\n';
                ++ctr;
            }
        }
    }

    std::cout << "Ilość liczb zaprzyjaźnionych: " << ctr << '\n';
}
