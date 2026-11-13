#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>


// ============================================= CONFIGURATION =======================================

const std::string INPUT_FILES[3] {"bloki1.txt", "bloki2.txt", "bloki3.txt"};
const std::string OUTPUT_FILES[3] {"wyniki1.txt", "wyniki2.txt", "wyniki3.txt"};

// ===================================================================================================


size_t findMaxBlockBrute(const std::vector<short>& nums) {
    size_t maxBlock = 0;
    size_t n = nums.size();

    for (size_t i = 0; i < n; i++) {
        if (n - i <= maxBlock) break; 

        unsigned long long currentSum = 0;
        for (size_t j = i; j < n; j++) {
            currentSum += nums[j];
            if (currentSum % 3 == 0) {
                size_t currentLen = j - i + 1;
                if (maxBlock < currentLen) {
                    maxBlock = currentLen;
                }
            }
        }
    }
    return maxBlock;
}

int main() {
    for (size_t f = 0; f < 2; f++) {
        std::ifstream inputFile(INPUT_FILES[f]);
        if (!inputFile) { std::cerr << "ERROR: " << INPUT_FILES[f] << " not found\n"; return 1; }

        std::vector<short> nums;
        nums.reserve(30000);

        short val;
        while (inputFile >> val) {
            nums.push_back(val);
        }
        
        size_t result = findMaxBlockBrute(nums);

        std::cout << INPUT_FILES[f] << " : " << result << '\n';

        std::ofstream outputFile(OUTPUT_FILES[f]);
        outputFile << result << '\n';
    }

    return 0;
}