#include <iostream>
#include <fstream>



// ================================== CONFIGURAIONS ===============================

const std::string INPUT_FILE_NAMES[] = { "dane5-1.txt", "dane5-2.txt", "dane5-3.txt" };

// ================================================================================


int main()
{
    for (const std::string& fileName : INPUT_FILE_NAMES)
    {
        std::ifstream inputFile(fileName);
        if (!inputFile) { std::cerr << "Error while opening inputFile\n"; return -1; }

        int crrInt; inputFile >> crrInt;

        int maxSum = crrInt,
        lSum = crrInt;

        while (inputFile >> crrInt)
        {
            lSum = std::max (crrInt, lSum + crrInt);
            if (maxSum < lSum) { maxSum = lSum; }
        }
        std::cout << "najlepsza suma cyfr dla pliku " << fileName << '\n';
        std::cout << maxSum << "\n";
    }

}