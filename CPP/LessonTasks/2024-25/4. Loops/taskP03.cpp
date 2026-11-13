#include <iostream>
using namespace std;

int main() {
    cout << "Zadanie P03.cpp.  Pętla FOR" << endl << endl;

    for (int i = 0; i < 100; i += 2) {
        cout << i << ' ';
    }

    cout << endl << endl << "Pętla WHILE" << endl << endl;

    int iter = 1;

    while (iter < 100) {
        cout << iter << ' ';
        iter += 2;
    }

    return 0;
}
