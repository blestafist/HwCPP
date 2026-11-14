#include <array>
#include <iostream>


// Time complexity: O(sqrt(n))
// Space complexity: O(1)
long long SumProperDivisors(long long num) {
    if (num <= 1) { return 0; }

    long long sum = 1;
    for (long long i = 2; i <= num / i; ++i) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) { sum += num / i; }
        }
    }
    return sum;
}


// Time complexity: O(sqrt(n))
// Space complexity: O(1)
bool IsPerfect(long long num) {
    if (num < 6) { return false; }
    return SumProperDivisors(num) == num;
}


int main() {
    constexpr std::array<long long, 4> nums {496, 8128, 33550336, 8589869056};

    long long num = 0;
    std::cout << "Podaj dowolna liczbe naturalna\n";
    std::cin >> num;

    std::cout << "liczba " << num << (IsPerfect(num) ? " jest doskonala" : " nie jest doskonala");
    std::cout << "\n\n";

    char label = 'b';
    std::cout << "a: ";
    for (size_t i = 0; i < nums.size(); ++i) {
        if (i > 1) { std::cout << label << ": "; ++label; }

        std::cout << "liczba " << nums[i] << (IsPerfect(nums[i]) ? " jest doskonala\n" : " nie jest doskonala\n");
    }

    return 0;
}
