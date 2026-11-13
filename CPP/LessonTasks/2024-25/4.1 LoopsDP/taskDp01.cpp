#include <iostream>
using namespace std;

int main() {
    for (int i = 10; i <= 99; i++) {
        for (int j = 1; j <= i / 2; j++) {
            float s1 = j, s2 = i - j, licz = i;

            if (1 / s1 + 1 / s2 == licz / 100) {
                cout << i << " -- " << s1 << " + " << s2 << endl;
            }
        }
    }

    return 0;
}
