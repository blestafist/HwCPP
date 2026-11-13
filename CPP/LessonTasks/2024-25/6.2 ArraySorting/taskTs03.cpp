#include <bits/stdc++.h>
using namespace std;

void generateArray(int* arr) {
    for(int i = 0; i < 10; i++) {
        *(arr + i) = rand() % 21 + 20;

        for (int j = 0; j < i; j++) {
            if (*(arr + i) == *(arr + j)) { i--; break; }
        }
    }
}

void printArray(int* arr) {
    for (int i = 0; i < 10; i++) {
        cout << *(arr + i) << ' ';
    } cout << endl << endl;
}

void sortArray(int* arr) {
    int clipBoard;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                clipBoard = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = clipBoard;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int arr[10], clipBoard;

    generateArray(arr);
    printArray(arr);

    sortArray(arr);
    printArray(arr);
}
