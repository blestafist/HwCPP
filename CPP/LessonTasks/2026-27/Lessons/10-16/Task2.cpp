#include <iostream>
#include <fstream>
#include <string>


const std::string INPUT_FILE = "zadanie1_sortowanie_insertion.txt";
const std::string OUTPUT_FILE = "zadanie2.txt";


template<size_t len>
void ErastInit (bool (&arr)[len]) {
    arr[0] = false; arr[1] = false;

    for (size_t i = 2; i < len; ++i) {
        arr[i] = true;
    }
}

template<size_t len>
void ErastGen (bool (&arr)[len]) {
    for (size_t i = 2; i * i < len; ++i) {
        if (!arr[i]) { continue; }

        for (size_t j = i * i; j < len; j += i) {
            arr[j] = false;
        }
    }
}


int main () {
    std::ifstream inputFile (INPUT_FILE);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }

    std::ofstream outputFile (OUTPUT_FILE);

    bool arr[1000001];

    int num;

    ErastInit(arr);
    ErastGen(arr);

    while (inputFile >> num) {
        if (num >= 0 && num <= 1000000 && arr[num]) {
            std::cout << num << "\n";
            outputFile << num << '\n';
        }
    }

    return 0;
}
