#include <stdio.h>

enum Color {
    RED = 1,
    GREEN,
    BLUE
};

void PrintColor(enum Color col) {
    switch (col) {
        case RED:
            printf("RED");
            break;
        case GREEN:
            printf("GREEN");
            break;
        case BLUE:
            printf("BLUE");
            break;
            
        default:
            printf("No color specified");
            break;
    }

    printf("\n");
    return;
}

int main() {
    enum Color c;
    PrintColor(c);
    return 0;
}