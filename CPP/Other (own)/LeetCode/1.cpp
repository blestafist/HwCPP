#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <map>
#include <stack>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    for (int i : nums2) {
        nums1.push_back(i);
    }

    std::sort(nums1.begin(), nums1.end());

    if (nums1.size() % 2 == 0) {
        return (double)(nums1[(nums1.size() / 2) - 1] + nums1[(nums1.size() / 2)]) / 2;
    }

    else {
        return nums1[nums1.size() / 2];
    }
}

int lengthOfLongestSubstring(string s) {
    std::unordered_set<char> seen;
    int left, highest = 0;

    for (int right = 0; right < s.size(); right++) {
        while (seen.count(s[right])) { // count returns 0 or 1
            seen.erase(s[left]);
            left++;
        }

        seen.insert(s[right]);

        highest = std::max(highest, right - left + 1);
    }

    return highest;
}

int ConainerWithMostWater(vector<int>& height) {
    int maxWater = 0, water;
    int leftPtr = 0, rightPtr = height.size() - 1;

    while (leftPtr != rightPtr) {
        if (height[leftPtr] < height[rightPtr]) {
            water = height[leftPtr] * (rightPtr - leftPtr);
            if (water > maxWater) { maxWater = water; }
            leftPtr++;
        }

        else {
            water = height[rightPtr] * (rightPtr - leftPtr);
            if (water > maxWater) { maxWater = water; }
            rightPtr--;
        }
    }

    return maxWater;
}

vector<string> letterCombinations(string digits) {
    vector<string> result;

    map<char, string> origin = { // origin map
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'3', "wxyz"},
    };

    string originStr = "";
    for (char c : digits) {
        originStr += origin[c];
    }

    for (int i = 0; i < originStr.size(); i++) {
        for (int j = i; j < originStr.size(); j++) {
            
        }
    }
}

bool ValidParentheses(string s) {
    stack<char> seen;

    map<char, char> matching = {
        { '}', '{' },
        { ']', '[' },
        { ')', '(' }
    };

    for (char c : s) {
        if (c == '{' || c == '[' || c == '(') {
            seen.push(c); continue;
        }

        else if (matching.count(c)) {
            if (seen.empty() || seen.top() != matching[c]) { return false; }
            seen.pop();
        }
    }

    return seen.empty();
}

int lengthOfLastWord(string s) {
    bool occFirstLetter = false;
    int count = 0;

    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] != ' ') { occFirstLetter = true; count++; }
        else if (occFirstLetter) {
            return count;
        }
    }

    return count;
}

bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) { return false; }
    int reversed = 0;

    while (x > reversed) {
        reversed = (reversed * 10) + (x % 10);
        x /= 10;
    } 

    return x == reversed || x == reversed / 10;
}
