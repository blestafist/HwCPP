#include <iostream>
using namespace std;

int main() {
    int p = 1;

    for (int i = 1; i <= 10; i++) {
        p = 1;
        for (int j = 0; j < i; j++) {
            p *= i;
        }
        cout << p << ' ';
    }
}
