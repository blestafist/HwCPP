#include <iostream>
using namespace std;

bool isDividable(int num) {
    if (num < 2) { return false; }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) { return false; }
    } return true;
}

bool isNumCorrect(int num) {
    int support = 1;
    while (num > 0) {
        if (support % 2 != num % 2) { return false; }
        support++;
        num /= 10;
    } return true;
}

int main() {
    int counter = 0;
    for (int i = 100; i <= 10000; i++) {
        if (isDividable(i) and isNumCorrect(i)) {
            if (i < 1000) { cout << ' '; }
            cout << i << ' ';
            counter++;
            if (counter & 10 == 0) { cout << endl; }
        }
    }
}
