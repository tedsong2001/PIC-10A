#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main () {
    
    cout << "Please enter a two digit number. (The smallest number allowed is 10 and the largest number allowed is 99.)" << endl;
   
    /* user inputs number */
    int number;
    cin >> number;
    
    /* assign digits to variables */
    int tens_digit = number / 10; // formula for getting tens digit
    int ones_digit = number % 10; // formula for getting ones digit
    double larger_digit = max(tens_digit , ones_digit); // gets larger digit
    double smaller_digit = min(tens_digit , ones_digit); // gets smaller digit
    
    /* prints user's number*/
    cout << "Your number is: " << number << endl;
    
    /* prints tens digit */
    cout << "The tens digit is: " << tens_digit << endl;
    
    /* prints ones digit */
    cout << "The ones digit is: " << ones_digit << endl;
    
    /* prints larger digit */
    cout << "The larger digit is: " << larger_digit << endl;
    
    /* required comment */
    cout << "In order to do the calculation on the line above, I wrote #include <algorithm> in the top of this file." << endl;
    
    /* prints sum of tens and ones digit */
    cout << "The sum of the digits is: " << (tens_digit + ones_digit) << endl;
    
    /* prints product of tens and ones digit */
    cout << "The product of the digits is: " << (tens_digit * ones_digit) << endl;
    
    /* prints absolute difference of tens and ones digit */
    cout << "The absolute difference of the digits is: " << abs(tens_digit - ones_digit) << endl;
    
    /* prints quotient of larger digit divided by smaller digit */
    cout << "When you divide the larger digit by the smaller digit, you get: " << larger_digit / smaller_digit << endl;
    
    return 0;
}
