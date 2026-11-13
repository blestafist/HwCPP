#include <iostream>
using namespace std;

int main()
{
    float weight, height, bmi;  // deklarowanie zmiennych

    cout << "Podaj wagę w kg: ";  // waga
    cin >> weight;

    cout << "Podaj wzrost w cm: ";  // wzrost
    cin >> height;

    bmi = weight / ((height / 100) * (height / 100));  // obliczenie BMI

    cout << "Twoje BMI wynosi: " << bmi;  // Wyświetlenie BMI

    return 0;
}
