#include <iostream>
#include <sys/types.h>
#include <vector>
#include <cstdint>
#include <array>

static constexpr std::array<uint32_t, 15> moneyNominals = {
    1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 
    10000, 20000, 50000
};


struct Normalised {
    uint32_t value;
    bool isZloty;
};


std::vector<uint32_t> SplitNominals (ulong input) {
    std::vector<uint32_t> result;
    
    for (size_t i = moneyNominals.size() - 1; i >= 0; --i) {
        if (input > moneyNominals[i]) {
            size_t howMany = input / moneyNominals[i];
            for (size_t hm = 0; hm < howMany; ++hm) { result.push_back(moneyNominals[i]); }
            input = input % moneyNominals[i];
        }
        
        if (input <= 0) { break; }
    }

    return result;
}


Normalised NormaliseValues (uint32_t nom) {
    if (nom >= 100) {
        return { nom / 100, true };
    }
    return { nom, false };
}


int main () {
    double input;
    std::cout << "Input value: ";
    std::cin >> input;

    int toOperate = input * 100; // convert to grosze

    std::vector<uint32_t> result = SplitNominals(toOperate);

    for (auto nom : result) {
        Normalised normalised = NormaliseValues(nom);
        std::cout << normalised.value << ' ' << ( normalised.isZloty ? "zł" : "gr" ) << '\n';
    }

    return 0;
}
