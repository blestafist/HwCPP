#include <stdlib.h>
#include <stdio.h>

void reverse(char* str) {
    char* start = str;
    char* end = str; // place two pointers on the begin of string

    while (*end != '\0') { // пока не встретим ноль-терминатор
        end++; // сдвигаем на один байт
    }
    end--; // делаем шаг назад чтобы не включать ноль в строку

    while (start < end) { // идем пока не встретятся
        char temp = *start;
        *start = *end;
        *end = temp; // свапаем через доп переменную

        start++; // двигаем начало влево
        end--; // а конец вправо
    }
}

int main() {
    char str[10]; // создание массива чаров - строка
    str[0] = 'H'; str[1] = 'e'; str[2] = 'l'; str[3] = 'l'; str[4] = 'o'; str[5] = '\0'; // writing data to a string (with term. 0)
    printf("%s\n", str);
    str[1] = '\0';
    printf("%s\n", str);

    char war[] = "Warsaw"; // len is 7 → Warsaw is 6 long + \0
    reverse(war); 
    printf("%s\n", war);

    return 0;
}
