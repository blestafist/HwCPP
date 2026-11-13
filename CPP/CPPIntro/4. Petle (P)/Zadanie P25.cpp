#include <iostream>
using namespace std;

int main() {
    int przyprostokątna;
    bool isCorrectInput = false;

    do {
        cout << "Podaj długość przyprostokątnej: ";
        cin >> przyprostokątna;

        if (przyprostokątna <= 20 and przyprostokątna > 1) {
            isCorrectInput = true;
        }

        else {cout << "Eblan" << endl;}

    } while (isCorrectInput == false);

    for (int i = 0; i < przyprostokątna + 1; i++) {
        for (int j = 0; j < i; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
