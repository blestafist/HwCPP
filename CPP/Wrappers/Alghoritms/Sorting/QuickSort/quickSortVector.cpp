#include <vector>

int PartitionQuickSort(std::vector<int>& arr, int first, int last) {
    int pivot = arr[last]; // defining a pivot element (so lower → left, higher → right)
    int fence = first - 1; // a "fence", that we'll be moving during the alghoritm

    for (int i = first; i < last; ++i) {
        if (arr[i] <= pivot) {
            ++fence; 
            std::swap(arr[fence], arr[i]);
        }
    }

    ++fence;

    std::swap(arr[fence], arr[last]); // last not included, because it is pivot
    return fence; // returning a new fence to get 2 new arrays;
}

void QuickSortRec(std::vector<int>& arr, int first, int last) {
    if (first < last) {
        int piv = PartitionQuickSort(arr, first, last);

        QuickSortRec(arr, first, piv - 1);
        QuickSortRec(arr, piv + 1, last);
    }
}

void QuickSort(std::vector<int>& arr) { // main func (WRAPPER)
    if (arr.size() <= 1) { return; } // checking if array is empty to not to fall into segmentation fault
    QuickSortRec(arr, 0, arr.size() - 1);
}
