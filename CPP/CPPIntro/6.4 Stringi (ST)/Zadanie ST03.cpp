#include <iostream>
using namespace std; int main() { string str; getline(cin, str); if (str.size() % 2 == 0) {cout << "Nie ma środkowego znaku! "; return 0; } cout << str[str.size() / 2]; }
