#include <iostream>
#include <cstddef>
#include <vector>

std::vector<int> DivideNumInPieces (int num) {
    std::vector<int> result;
    
    while (num > 1) {
        bool divided = false;

        for (size_t i = 2; i * i < num; ++i) {
            if (num % i == 0) {
                result.push_back(i);
                divided = true;
                num /= i;
            }
        }

        if (!divided) { result.push_back(num); break; }
    }

    return result;
}


int main () {
    int num;

    std::cout << "Enter the first num: ";
    std::cin >> num;

    std::cout << "\n\nResult: \n";

    std::vector<int> res = DivideNumInPieces(num);

    for (auto i : res) {
        std::cout << i << " ";
    }

    return 0;
}