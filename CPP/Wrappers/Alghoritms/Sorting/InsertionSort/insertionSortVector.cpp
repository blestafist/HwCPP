#include <cstdlib> // for size_t
#include <vector>  // for vecotr (dynamic c++ arr)

template <typename T>
void InsertionSort(std::vector<T>& arr) {
    size_t arrLen = arr.size();
    for (size_t i = 1; i < arrLen; ++i) {
        T temp = arr[i];

        size_t searcher = i;
        while (searcher > 0 && arr[searcher - 1] > temp) {
            arr[searcher] = arr[searcher - 1];
            --searcher;
        }

        arr[searcher] = temp;
    }
}
