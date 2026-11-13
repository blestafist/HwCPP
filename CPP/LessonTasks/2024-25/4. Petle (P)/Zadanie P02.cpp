#include <iostream>
using namespace std;

int main() {
    cout << "P02.cpp. Pętla FOR" << endl << endl;

    for (int i = 99; i >= 0; i--) {
        cout << i << ' ';
    }

    cout << endl << endl << "Pętla WHILE" << endl << endl;

    int iter = 99;
    while (iter >= 0) {
        cout << iter << ' ';
        iter--;
    }

    return 0;
}
