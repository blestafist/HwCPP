#include <functional>
#include <iostream>
#include <cstdint>
#include <map>
#include <array>
#include <cmath>


static constexpr std::array<uint32_t, 15> PLN_NOMINALS = {
    1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 
    10000, 20000, 50000
};


class Denomination {
    public:
        uint32_t value;
        bool isPLN;

        Denomination (uint32_t grosze) {
            if (grosze >= 100) {
                value = grosze / 100;
                isPLN = true;
            } else {
                value = grosze;
                isPLN = false;
            }
        }
};


std::map<uint32_t, size_t, std::greater<>> SplitAmount (uint64_t input) {
    std::map<uint32_t, size_t, std::greater<>> result;
    
    for (int i = PLN_NOMINALS.size() - 1; i >= 0; --i) {
        if (input >= PLN_NOMINALS[i]) {
            result[PLN_NOMINALS[i]] = input / PLN_NOMINALS[i];
            input = input % PLN_NOMINALS[i];
        }
        
        if (input <= 0) { break; }
    }

    return result;
}


int main () {
    double amountPLN;
    std::cout << "Enter value in PLN: ";
    std::cin >> amountPLN;

    if (amountPLN < 0) return 1;
    
    uint64_t totalGrosze = std::round(amountPLN * 100);
    std::map<uint32_t, size_t, std::greater<>> result = SplitAmount (totalGrosze);

    for (auto [value, quantity] : result) {
        Denomination denom (value);
        std::cout << denom.value << ' ' << ( denom.isPLN ? "zł" : "gr" ) << " → " << quantity << '\n';
    }

    return 0;
}
