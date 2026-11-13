#include <iostream>

int main()
{
    int arr[]{1, -2, 6, -5, 7, -3},
    lSum = arr[0],
    maxSum = arr[0];

    for (int i = 1; i < 6; i++)
    {
        lSum += arr[i];
        if (lSum < 0) { lSum = 0; }
        if (lSum > maxSum) { maxSum = lSum; }
    }

    std::cout << maxSum;
    
}