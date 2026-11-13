#include <iostream>
#include <vector>


static constexpr char vals [] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8',
    '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'
};


std::string convertToSystem (int decimal, int base) {
    std::string result = "";

    while (decimal > 0) {
        result = vals[decimal % base] + result;
        decimal /= base;
    }

    return result;
}


int main () {
    std::vector<int> nums = { 17, 89, 109, 994, 8706 };
    std::vector<int> bases = { 5, 7, 11, 14 };

    for (auto num : nums) {
        for (auto base : bases) {
            std::cout << num << " in " << base << ": " << convertToSystem(num, base) << "\n";
        }
    }

    return 0;
}
