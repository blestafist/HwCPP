#include <iostream>

// =========================== CONFIGURATION ===========================

const int MIN = 100;
const int MAX = 1000;

// =====================================================================

bool Has2PrimeDividers(int num) {
    int ctr = 0, div = 2;
    while (num > 1 && ctr < 3) {
        if (num % div == 0) { ++ctr; num /= div; }
        else { ++div; }
    }
    return ctr == 2;
}

int main() {
    size_t ctr = 0;
    for (int i = MIN; i <= MAX; ++i) {
        if (Has2PrimeDividers(i)) {
            ++ctr;
        }
    }
    std::cout << "Ilość liczb półpierwszych w przedziale <" << MIN << ";" << MAX << ">: " << ctr << '\n';
    return 0;
}
