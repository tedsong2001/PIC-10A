#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main () {
    cout << "Please enter an integer between 1 and 999,999,999." << endl;
    string integer;
    cin >> integer;
    double LENGTH = integer.length();
    // following statement will remove commas for numbers 1,000,000-999,999,999
    if (LENGTH >= 9) {
        integer.erase(integer.end() - 8);
        integer.erase(integer.end() - 4);
    }
    // following statement will remove commas for numbers 1,000-999,999
    else if (LENGTH >= 5 && LENGTH < 9) {
        integer.erase(integer.end() - 4);
    }
    // numbers 1-999 will remain the same
    else {
        integer = integer;
    }
    cout << "Your number with comma(s) removed: " << integer << "." << endl;
    
    char largest_digit = '0';
    char smallest_digit = '9';
    for (int i = 0; i < integer.length(); ++i) {
        largest_digit = max(largest_digit , integer[i]);
        smallest_digit = min(smallest_digit , integer[i]);
    }
    cout << "Largest digit: " << largest_digit << endl;
    cout << "Smallest digit: " << smallest_digit << endl;
    
    return 0;
}
