#include <climits>
#include <iostream>
#include <fstream>
#include <numeric>
#include <unordered_map>
#include <vector>

const std::string INPUT_FILE = "input.txt";


unsigned int MultiplyASCIICode (const std::string& str) {
    unsigned int res = 1;

    for (char c : str) {
        res *= static_cast<unsigned int>(c);
    }

    return res;
}



int main () {
    std::ifstream inputFile (INPUT_FILE);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }

    std::string tempWord;
    unsigned long max = 0, min = UINT_MAX;

    std::vector<unsigned long> arr = {};
    std::unordered_map<unsigned long, unsigned long> mp = {};

    while (inputFile >> tempWord) {
        unsigned long res = MultiplyASCIICode(tempWord);
        arr.push_back(res);
        mp[res]++;
    }

    unsigned long nwdAll = arr[0];

    for (auto i : arr) {
        nwdAll = std::gcd (i, nwdAll);
        if (min > i) {
            min = i;
        } if (max < i) {
            max = i;
        }
    }

    for (auto [key, value] : mp) {
        std::cout << key << ": " << value << "\n";
    }

    std::cout << "\n\nnext: \nmax: " << max << "\n";
    std::cout << "min: " << min << "\n";

    std::cout << "nwd: " << std::gcd(max, min) << "\n";
    std::cout << "nwdAll: " << nwdAll << "\n";

    return 0;
}
