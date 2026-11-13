#include <iostream>   // nie wiem dlaczego ale bits/stdc++ nie dziala w Visual Studio 2022
#include <cstdlib>
#include <time.h>

using namespace std; 

void printArray(int* arr) {
	for (int i = 0; i < 10; i++) {
		cout << *(arr + i) << ' ';
	} cout << endl << endl;
}

void generateArrAndPrint(int* arr) {
	for (int i = 0; i < 10; i++) {
		*(arr + i) = rand() % 90 + 10;
		cout << *(arr + i) << ' ';
	} cout << endl << endl;
}


int main() {  // точка входа
	srand(time(NULL));

	int arr[10], clipBoard;

	generateArrAndPrint(arr); // generowanie tablicy

	for (int i = 0; i < 9; i++) {   // пузырьковая сортировка по возрастанию
		for (int j = 0; j < 9 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				clipBoard = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = clipBoard;
			}
		}
	}

	printArray(arr);

	for (int i = 0; i < 9; i++) {   // пузырьковая сортировка по возрастанию
		for (int j = 0; j < 9 - i; j++) {
			if (arr[j] < arr[j + 1]) {
				clipBoard = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = clipBoard;
			}
		}
	}

	printArray(arr);

}