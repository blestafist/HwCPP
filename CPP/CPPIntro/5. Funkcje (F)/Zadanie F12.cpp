#include <bits/stdc++.h>
using namespace std;

bool isDividable(int num) {
    if (num < 2) {return false;}
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {return false;}
    } return true;
}

bool isCorrectIRA(int num) {
    int lastNum;
    int copyNum;
    while (num > 0) {
        lastNum = num % 10;
        num /= 10;
        copyNum = num;
        while (num > 0) {
            if (num % 10 == lastNum) {return true;}
            num /= 10;
        }
        num = copyNum;
    } return false;
}

bool isCorrectKubelki(int num) {
    int tab[10] {};
    while (num > 0) {
        tab[num % 10]++;
        num /= 10;
    }

    for (int i = 0; i < 10; i++) {
        if (tab[i] > 1 ) {return true;}
    } return false;
}

bool isCorrectMatviej(int num) {
    int copyNum = num;
    int counter = 0;

    for (int i = 0; i < 10; i++) {
        num = copyNum;
        while (num > 0) {
            if (num % 10 == i) { counter++; }
            num /= 10;
        }
        if (counter > 1) {return true;}
        counter = 0;
    } return false;
}

bool isCorrectMine(int num) {
    string numStr = to_string(num);
    char firstChar;
    while (numStr.size() != 0) {
        firstChar = numStr[0];
        numStr.erase(0, 1);
        if (numStr.find(firstChar) != string::npos) {
            return true;
        }
    } return false;
}


int main() {
    for (int i = 1000; i <= 2000; i++) {
        if (isDividable(i) and isCorrectMine(i)) {
            cout << i << ' ';
        }
    }
}
