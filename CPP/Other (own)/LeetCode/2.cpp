#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <limits.h>

using namespace std;


int titleToNumber(string columnTitle) {
    int result = 0;

    for (char c : columnTitle) {
        int digit = c - 'A' + 1;
        result = (result * 26) + digit;
    }

    return result;
}


int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    // ! A is a first rectangle
    // ! B is a second rectangle

    int rectangleCoverArea;
    rectangleCoverArea = abs(bx1 - ax2) * abs(by1 - ay2);
}

int mySqrt(int x) {
    if (x < 2) { return x; }

    int left = 2, right = x / 2;
    int mid, res = 1;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (mid <= x / mid) //x eq to mid * mid <= x
        {
            res = mid; // remebmering a possible result
            left = mid + 1;
        }
        else { right = mid - 1; }
    }

    return res;
}

string convertToTitle(int columnNumber) {
    string result = "";

    while (columnNumber > 0) {
        columnNumber -= 1;
        char c = (columnNumber % 26) + 'A';
        result += c;
        columnNumber /= 26;
    }

    std::reverse(result.begin(), result.end());

    return result;
}

int addDigits(int num) { // 258. Add Digits
    if (num == 0) { return 0; }
    if (num % 9 == 0) { return 9; }
    return num % 9;
}

int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, mid, res;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (target == nums[mid]) { return mid; }
        else if (target < nums[mid]) {
            res = mid;
            right = mid - 1;
        }
        else {
            res = mid + 1;
            left = mid + 1;
        }
    }

    return res;
}

vector<string> fizzBuzz(int n) {
    vector<string> vec;

    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) { vec.push_back("FizzBuzz"); }
        else if (i % 3 == 0) { vec.push_back("Fizz"); }
        else if (i % 5 == 0) { vec.push_back("Buzz"); }
        else {
            vec.push_back(to_string(i));
        }
    }

    return vec;
}


int majorityElement(vector<int>& nums) {
    unordered_map<int, int> hashMap;
    int maxEl = INT_MIN,
    maxElKey;


    for (auto element : nums) {
        hashMap[element]++;
        if (hashMap[element] >= maxEl) {
            maxEl = hashMap[element];
            maxElKey = element;
        }
    }

    return maxElKey;
}


int majorityElement2(vector<int>& nums) {
    int major = nums[0], ct = 1;

    for (int i = 1; i <= nums.size(); ++i) {
        if (ct == 0) {
            ++ct;
            major = nums[i];
        }
        else if (nums[i] == major) { ++ct; }
        else { --ct; }
    }

    return major;
}

int PartitionQuickSort(std::vector<int>& arr, int first, int last) {
    int pivot = arr[last]; // defining a pivot element (so lower → left, higher → right)
    int fence = first - 1; // a "fence", that we'll be moving during the alghoritm

    for (int i = first; i < last; i++) {
        if (arr[i] <= pivot) {
            ++i; 
            std::swap(arr[fence], arr[i]);
        }
    }

    ++fence;

    std::swap(fence, last); // last not included, because it is pivot
    return fence; // returning a new fence to get 2 new arrays;
}

void QuickSortRec(std::vector<int>& arr, int first, int last) {
    if (first < last) {
        int piv = PartitionQuickSort(arr, first, last);

        QuickSortRec(arr, first, piv - 1);
        QuickSortRec(arr, piv + 1, last);
    }
}

void QuickSort(std::vector<int>& arr) {
    if (arr.size() <= 1) { return; } // checking if array is empty to not to fall into segmentation fault
    QuickSortRec(arr, 0, arr.size() - 1);
}
