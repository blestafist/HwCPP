#include <utility>
// ! QuickSort for Legacy Arrays (C)

int PartitionQuickSort(int (&arr)[], int first, int last) {
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

void QuickSortRec(int (&arr)[], int first, int last) {
    if (first < last) {
        int piv = PartitionQuickSort(arr, first, last);

        QuickSortRec(arr, first, piv - 1);
        QuickSortRec(arr, piv + 1, last);
    }
}

void QuickSortLegacy(int (&arr)[], int length) {
    if (length <= 1) { return; }
    QuickSortRec(arr, 0, length - 1);
}
