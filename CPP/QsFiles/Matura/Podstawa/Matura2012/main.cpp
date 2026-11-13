#include <iostream>
#include <fstream>


// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE = "cyfry.txt";
const std::string OUTPUT_FILE = "zadanie4.txt";

// ======================================================================

bool IsEven(int tempInt)
{
    return tempInt % 2 == 0;
}


int SumOfNumbers(int tempInt)
{
    int sum = 0;
    while (tempInt > 0)
    {
        sum += tempInt % 10;
        tempInt /= 10;
    }
    return sum;
}


bool IsGrowingSequence(int tempInt)
{
    
    while (tempInt >= 10)
    {
        int last = tempInt % 10;
        int prev = (tempInt / 10) % 10;

        if (prev >= last) { return false; }

        tempInt /= 10;
    }
    return true;
}


int main()
{
    std::ifstream inputFile (INPUT_FILE);
    std::ofstream outputFile (OUTPUT_FILE);

    if (!inputFile.is_open()) { std::cout << "error open file"; return -1; }

    int tempInt, counter = 0;

    while (inputFile >> tempInt)
    {
        if (IsEven(tempInt)) { counter++; }
    }

    std::cout << "zadanieA" << std::endl << counter << std::endl;
    outputFile << "zadanieA" << std::endl << counter << std::endl;

    inputFile.close();
    inputFile.open(INPUT_FILE);

    inputFile >> tempInt;

    int maxNum = tempInt;
    int minNum = tempInt;

    while (inputFile >> tempInt)
    {
        if ( SumOfNumbers(maxNum) < SumOfNumbers(tempInt) ) { maxNum = tempInt; }
        if ( SumOfNumbers(minNum) > SumOfNumbers(tempInt) ) { minNum = tempInt; }
    }
    
    std::cout << "zadanieB" << std::endl << "największa suma cyfr: " << maxNum << std::endl << "najmniejsza suma cyfr: " << minNum <<std::endl;
    outputFile << "zadanieB" << std::endl << "największa suma cyfr: " << maxNum << std::endl << "najmniejsza suma cyfr: " << minNum <<std::endl;

    std::cout   << "zadanieC" <<std::endl;
    outputFile  << "zadanieC" << std::endl;

    inputFile.close();
    inputFile.open(INPUT_FILE);

    while (inputFile >> tempInt)
    {
        if (IsGrowingSequence(tempInt)) {std::cout << tempInt << std::endl; outputFile << tempInt << std::endl;}
    }

    inputFile.close();
    outputFile.close();
}

/* 

Мои замечания: пишу снизу чтобы код не портить

1. Убери using namespace std;
2. Константы лучше отделять комментами с ================
3. Больше отступы между функциями (по 2 endl между логическимим блоками)
4. return tempInt % 2 == 0 ? true : false; → тернарный оператор не нужен. Можно просто return tempInt % 2 == 0;
5. Пробелы после if, for, while
6. На 19 и 25 строке фигурные скобочки
7. Дальше как я понимаю еще не сделано тк там логические ошибки

*/

// с вектором некст сделаю