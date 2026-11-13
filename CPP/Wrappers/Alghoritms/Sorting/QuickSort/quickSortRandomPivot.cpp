#include <vector>
#include <cstdlib>
#include <ctime>

int PartitionQuickSort(std::vector<int>& arr, int first, int last) {
    // random pivot instead of always using last element (guards against O(n²) on sorted arrays)
    int randomIndex = first + rand() % (last - first + 1);
    std::swap(arr[randomIndex], arr[last]);
    
    int pivot = arr[last];
    int fence = first - 1;

    for (int i = first; i < last; ++i) {
        if (arr[i] <= pivot) {
            ++fence;
            std::swap(arr[fence], arr[i]);
        }
    }

    ++fence;
    std::swap(arr[fence], arr[last]);
    return fence;
}

void QuickSortRec(std::vector<int>& arr, int first, int last) {
    if (first < last) {
        int piv = PartitionQuickSort(arr, first, last);

        QuickSortRec(arr, first, piv - 1);
        QuickSortRec(arr, piv + 1, last);
    }
}

void QuickSortRandomPivot(std::vector<int>& arr) {
    if (arr.size() <= 1) { return; }
    srand(time(NULL)); // seed initialization for random pivot
    QuickSortRec(arr, 0, arr.size() - 1);
}
