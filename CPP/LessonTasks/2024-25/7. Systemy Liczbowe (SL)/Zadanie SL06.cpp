#include <iostream>
using namespace std;

int Multiply(int num, int upNum) {
    int result = 1;
    for (int i = 0; i < upNum; i++) {
        result *= num;
    } return result;
}

int Convert(string num, int sys) {
    int result = 0;
    for (int i = 0; i < num.size(); i++) {
        result += Multiply(sys, i) * (num[num.size() - 1 - i] - 48);
    }
    return result;
}

int main() {
    string num;
    int sys;
    cout << "Podaj liczbę: ";
    cin >> num;

    cout << "Podaj system: ";
    cin >> sys;

    cout << endl << Convert(num ,sys);

}
