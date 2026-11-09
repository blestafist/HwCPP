#include <iostream>
#include <fstream>


bool IsEven (const std::string &tempString)
{
    return tempString.size() % 2 == 0;
}


bool AreSameDigitsCount (const std::string &tempString)
{
    int counter = 0;
    for (int i = 0; i < tempString.size(); i++)
    {
        tempString[i] == '0' ? counter++ : counter-- ; 
    }
    return counter == 0;
}
 
char DoesItConteinsOnlyZerosOrOnes (const std::string &tempString)
{
    char digit = tempString[0];
    for (int i = 1; i < tempString.size(); i++)
    {
        if(tempString[i] != digit) { return - 1 ;}
    }
    return digit;
}

void ArrSupplement (int arr[], std::string const &tempString)
{
    arr[tempString.size() - 2]++;
}

int main()
{
    std::string const INPUT_FILE = "napisy.txt";
    std::string const OUTPUT_FILE = "zadanie4.txt";

    std::ifstream inputFile(INPUT_FILE);
    std::ofstream outputFile(OUTPUT_FILE); // эту херь можешь открывать после закрытия inputFile.close()

    if (!inputFile) { std::cout << "error open file"; return -1; } // cout на cerr

    std::string tempString;


    int arr[15] {}, // можно сделать вот так и подписывать комментариями переменные
    counterOfEven = 0, 
    counterContainsOnlyZeros = 0, 
    counterContainsOnlyOnes = 0, 
    counterSameCharsQuantity = 0;


    while (inputFile >> tempString)
    {
        ArrSupplement(arr, tempString); // это можно без функции
        // arr[tempString.size() - 2]++;

        if (IsEven(tempString)) { counterOfEven++; } 
        // if (tempString.size() % 2 == 0) {}

        AreSameDigitsCount(tempString) ? counterSameCharsQuantity++ : 0;

        char result = DoesItConteinsOnlyZerosOrOnes(tempString); // выглядит прям максимально неплохо
        result == '0' ? counterContainsOnlyZeros++ :
        result == '1' ? counterContainsOnlyOnes++ : 0;
    }
        

    std::cout << "zadanieA" << '\n' << counterOfEven << '\n';
    outputFile << "zadanieA" << '\n' << counterOfEven << '\n';

    std::cout << "zadanieB" << '\n' << counterSameCharsQuantity <<'\n';
    outputFile << "zadanieB" << '\n' << counterSameCharsQuantity <<'\n';

    std::cout << "zadanieC" << '\n' <<  "ilosc liczb zawierajace same zera " << counterContainsOnlyZeros;
    outputFile << "zadanieC" << '\n' << "ilosc liczb zawierajace same zera " << counterContainsOnlyZeros;
    std::cout << '\n' <<  "ilosc liczb zawierajace same jedynki " << counterContainsOnlyOnes << '\n';
    outputFile << '\n' << "ilosc liczb zawierajace same jedynki " << counterContainsOnlyOnes << '\n';

    std::cout << "zadanieD" << '\n';
    outputFile << "zadanieD" << '\n';

    for (int i = 0; i < 15; i++)  // норм
    {
        std::cout << "napisów o " << i + 2 << " znakach" << " " <<arr[i] << '\n';
        outputFile << "napisów o " << i + 2 << " znakach" << " " <<arr[i] << '\n';
    }

    inputFile.close(); // закрытие файоа входа можно перенести прям после цикла, снизит риск огромного раздутия памяти
    outputFile.close();
}

/* 

1. Код хуйни
2. IsEven можно в функцию не писать по идее
3. В AreSameDigitsCount надо использовать foreach, в основном норм
4. В проверке на одну цифру логика неплоха, можешь добавить foreach / поменять на условие с флагом
5. Функция под ArrSuplement вроде даже не нужна, можно просто хуярить без функции как и IsEven
6. 38, 39 строчка вынеси в блок ====== в начале (тк константы)
7. Проверка открытия outputFile
8. Декларацию можно разделить на несколько строк, чтобы выглядело получше (я уже сделал)
9. 

*/