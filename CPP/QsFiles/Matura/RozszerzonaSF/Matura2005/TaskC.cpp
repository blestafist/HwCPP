#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>


// ============================================= CONFIGURATIONS =======================================

const std::string INPUT_FILE_NAMES [] {"dane5-1.txt", "dane5-2.txt", "dane5-3.txt" };

// ====================================================================================================


int main()
{
    for (const std::string& fileName : INPUT_FILE_NAMES)
    {
        std::ifstream inputFile(fileName);
        if (!inputFile) { std::cerr << "Error while opening inputFile\n"; return -1; }

        std::unordered_map<int, int> map; 

        int tempInt,
        maxOccValue = 0;

        std::vector<int> keys;

        while (inputFile >> tempInt)
        {
            map[tempInt]++; 
        }

        for (const auto& [key, value] : map)
        {
            if (maxOccValue < value) { maxOccValue = value; keys = {key}; }
            else if (maxOccValue == value) { keys.push_back(key); }
        }

        std::cout << "dla pliku " << fileName << ": ";
        for (int i : keys)
        {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
}