#include <iostream>
#include <utility> // for std::swap
#include <random> // for random num generation (std::random_device, std::mt19937)

template<typename T, size_t len> // using template for type of array and len of array
void SelectionSort(T (&arr)[len], bool changeOrder = false) {
    for (size_t shift = 0; shift + 1 < len; ++shift) { // shift + 1 < len is same as shift < len - 1 but safer for size_t (unsigned int)
        size_t bestIndex = shift;

        // find index of the best element (min or max depending on order)
        for (size_t fastPtr = shift + 1; fastPtr < len; ++fastPtr) { // scan the rest of the array to find the best element
            const bool shouldSwap = changeOrder ? 
                arr[fastPtr] > arr[bestIndex] : 
                arr[fastPtr] < arr[bestIndex]; // choose comparison based on sorting order
                
            if (shouldSwap) { bestIndex = fastPtr; }
        }

        // swap if necessary
        if (bestIndex != shift) { std::swap(arr[bestIndex], arr[shift]); }
    }
}


template<typename T, size_t len>
void FillRandom(T (&arr)[len], int downRange, int upperRange) { // fill arr with random numbers using better random generator
    static std::random_device randomDevice; // seeding using device random
    static std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<T> distribution(downRange, upperRange); // distibution (диапазон) of nums

    for (size_t i = 0; i < len; ++i) {
        arr[i] = distribution(generator);
    }
}


template<typename T, size_t len>
void PrintArr(T (&arr)[len]) {
    for (auto i : arr) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}


int main() {
    int arr[10];

    FillRandom(arr, 100, 200);
    PrintArr(arr);

    SelectionSort(arr);
    PrintArr(arr);

    SelectionSort(arr, true);
    PrintArr(arr);

    return 0;
}
