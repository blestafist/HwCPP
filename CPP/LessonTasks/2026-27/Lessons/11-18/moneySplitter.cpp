#include <iostream>
#include <sys/types.h>
#include <vector>
#include <cstdint>
#include <array>

static constexpr std::array<uint32_t, 15> moneyNominals = {
    1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 
    10000, 20000, 50000
};


std::vector<uint32_t> SplitNominals (ulong input) {
    std::vector<uint32_t> result;1
    
    for (size_t i = moneyNominals.size() - 1; i >= 0; --i) {
        if (input <= 0) { break; }
    }
}


int main () {
    int input;
    std::cout << "Input value: ";
    std::cin >> input;

    std::vector<uint32_t> result = SplitNominals(input);

    for (auto nom : result) {
        std::cout << nom << ' ';
    }

    return 0;
}
