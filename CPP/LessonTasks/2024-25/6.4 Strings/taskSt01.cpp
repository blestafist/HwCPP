#include <iostream>
using namespace std; int main() { string str1, str2; getline(cin, str1); getline(cin, str2); cout << endl << endl; if (str1.size() < str2.size()) { cout << str1 << endl << str2; } else {cout << str2 << endl << str1; } }
