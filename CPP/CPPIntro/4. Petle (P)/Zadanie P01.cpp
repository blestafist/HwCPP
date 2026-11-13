#include <iostream>
using namespace std;

int main() {
    cout << "Pętle" << endl << endl;

    for(int i = 0; i < 100; i++) {
        cout << i << ' ';
    }

    cout << endl << endl;

    int iter = 0;
    while (iter < 100) {
        cout << iter << ' ';
        iter++;
    }

    return 0;
}
