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

        else {cout << "nope" << endl;}

    } while (isCorrectInput == false);

    for (int i = 0; i < przyprostokątna * 2; i+=2) {
        for (int a = 0; a < przyprostokątna - (i - przyprostokątna); a++)
            cout << ' ';

        for (int b = 0; b < i + 1; b++)
            cout << "* ";

        cout << endl;
    }

    return 0;
}

