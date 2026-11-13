#include <iostream>


bool IsPrime (int tempInt)
{
    if (tempInt < 2) { return false; }

    for (int i = 2; i * i <= tempInt; i++)
    {
        if (tempInt % i == 0) { return false; }
    }
    return true;
}


int SumOfDigits (int tempInt)
{
    int sum = 0;
    while (tempInt > 0) { sum += tempInt % 10; tempInt /= 10; }
    return sum;
}


bool IsBinarySumPrime (int tempInt)
{
    int sum = 0;
    
    while (tempInt > 0)
    {
        sum += tempInt % 2;
        tempInt /= 2;
    }
    return IsPrime(sum);
}


int main()
{
    int primeSumCounter = 0,
    sumOfSuperBPrime = 0;

    for (int i = 100; i <= 10000; i ++)
    {
        if (IsPrime(SumOfDigits(i))) { primeSumCounter++; }
        
        if (IsPrime(i) && IsPrime(SumOfDigits(i)) && IsBinarySumPrime(i)) { sumOfSuperBPrime += i; }
        
    }
   std::cout << "ilość liczb których suma cyfr jest pierwsza: " << primeSumCounter << "\n"; 

   if (IsPrime(sumOfSuperBPrime)) { std:: cout << "tak"; }
   else { std:: cout << "nie"; }
}
