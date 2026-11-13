# C++ Utility Functions

## Check if Number is Even
```cpp
bool IsEven(int number) {
    return number % 2 == 0;
}
```

## Check if String is Palindrome
```cpp
bool IsPalindrome(string word) {
    for(int i = 0; i < word.size() / 2; i++)
        if(word[i] != word[word.size() - i - 1])
            return false;
    return true;
}
```

## Sum of Digits
```cpp
int SumOfDigits(int number) {
    int sum = 0;
    while(number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}
```

## Check if String Characters are in Ascending Order
```cpp
bool IsAscending(string text) {
    for(int i = 0; i < text.size() - 1; i++)
        if(text[i] >= text[i + 1])
            return false;
    return true;
}
```

## Check if Number is Prime
```cpp
bool IsPrime(int number) {
    if(number < 2)
        return false;
    for(int i = 2; i * i <= number; i++)
        if(number % i == 0)
            return false;
    return true;
}
```