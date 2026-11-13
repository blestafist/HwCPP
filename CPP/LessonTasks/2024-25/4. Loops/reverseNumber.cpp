#include <iostream>
using namespace std;

int main() {
    int number, returnedNumber = 0;

    cout << "Wprowadż liczbę: ";
    cin >> number;

    while(number > 0) {
        returnedNumber = (returnedNumber * 10) + (number % 10);
        number /= 10;
    }

    cout << "Odwrócona liczba: " << returnedNumber;

    return 0;
}
