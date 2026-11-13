#include <bits/stdc++.h>
using namespace std;

void generateArrayAndPrint(int* arr) {
    for(int i = 0; i < 10; i++) {
        *(arr + i) = rand() % 90 + 10;
        cout << *(arr + i) << ' ';
    } cout << endl << endl;
}


void printArray(int* arr) {
    for (int i = 0; i < 10; i++) {
        cout << *(arr + i) << ' ';
    }
}

int main() {
    srand(time(NULL));
    int t[10], clipBoard;

    generateArrayAndPrint(t);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (t[j] > t[j + 1]) {
                clipBoard = t[j];
                t[j] = t[j + 1];
                t[j + 1] = clipBoard;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 5; j < 9; j++) {
            if (t[j] < t[j + 1]) {
                clipBoard = t[j];
                t[j] = t[j + 1];
                t[j + 1] = clipBoard;
            }
        }
    }

    printArray(t);
}
