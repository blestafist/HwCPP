#include <array>
#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>


// ============================================= CONFIGURATION =======================================

const size_t MOD_VALUE = 3;

const std::array<std::string, 3> INPUT_FILES { "bloki1.txt", "bloki2.txt", "bloki3.txt" };
const std::array<std::string, 3> OUTPUT_FILES { "wyniki1.txt", "wyniki2.txt", "wyniki3.txt" };

// ===================================================================================================


size_t FindMaxBlockFast (const std::vector<short>& nums) {
    size_t maxBlock = 0;

    // firstSeen[r] stores the earliest index where prefix_sum % MOD_VALUE == r
    std::array<int, MOD_VALUE> firstSeen;
    firstSeen.fill(-2);     // -2: Remainder not yet encountered
    firstSeen[0] = -1;      // -1: Virtual starting point for remainder 0

    unsigned long long currentSum = 0;
    size_t currentLen = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        currentSum += nums[i];
        int currRemainder = static_cast<int>(currentSum % MOD_VALUE);

        if (firstSeen[currRemainder] == -2) {firstSeen[currRemainder] = static_cast<int>(i); }
        else {
            // Remainder seen before, сalculate block length for existing remainder
            currentLen = i - firstSeen[currRemainder];  
            maxBlock = std::max(currentLen, maxBlock);
        }
    }
    return maxBlock; 
}


int main() {
    for (size_t f = 0; f < INPUT_FILES.size(); f++) {
        std::ifstream inputFile(INPUT_FILES[f]);
        if (!inputFile) { std::cerr << "ERROR: " << INPUT_FILES[f] << " not found" << std::endl; return 1; }

        std::vector<short> nums;
        if (f == 3) { nums.reserve(1000000); } // Third file

        short val;
        while (inputFile >> val) {
            nums.push_back(val);
        }
        
        size_t result = FindMaxBlockFast(nums);

        std::cout << INPUT_FILES[f] << " : " << result << '\n';

        std::ofstream outputFile(OUTPUT_FILES[f]);
        outputFile << result << '\n';
    }

    return 0;
}