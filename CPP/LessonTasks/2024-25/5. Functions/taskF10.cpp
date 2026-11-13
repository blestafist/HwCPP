#include <iostream>
#include <string>
using namespace std;

bool isDividable(int* num) {
    if (*num < 2) { return false; }
    for (int i = 2; i * i <= *num; i++) {
        if (*num % i == 0) { return false; }
    } return true;
}

bool isNumCorrect(int* num) {
    string numStr = to_string(*num);
    if (numStr[0] == numStr[numStr.size() - 1]) { return true; }
    return false;
}

int main() {
    for (int i = 10; i <= 1000; i++) {
        int* ptrI = &i;
        if (isDividable(ptrI) && isNumCorrect(ptrI)) { cout << i << ' '; }
    }
}
