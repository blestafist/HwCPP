#include <iostream>


void binary(double x, int k) {
    std::cout << "0,";
    double y = x;


    for (int i = 1; i <= k; ++i) {
        std::cout << y << ' ';
        if (y >= 0.5) { std::cout << "1"; } 
        else { std::cout << "0"; }
        
        y = y * 2;
        
        if (y >= 1) {
            y = y - 1;
        }
    }
    
    std::cout << y;
}


int main() {
    double x = 0.0625;
    int k = 4;

    binary(x, k);

    return 0;
}
