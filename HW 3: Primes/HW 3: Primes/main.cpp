#include <iostream>
using namespace std;

int main() {
    
    cout << "Please enter a positive integer." << endl;
    int input = 0;
    cin >> input;

    /* FIBONACCI NUMBER */
    int n1 = 1;
    int n2 = 2;
    size_t fibonacci = 0;
    if (input >= 4) {
        for (int i = 4; i <= input; i++) {
            fibonacci = n1 + n2;
            n1 = n2;
            n2 = fibonacci;
        }
    }
    else if (input == 3) { // When user's input is 3
        fibonacci = 2;
    }
    else if (input < 3) { // When user's input is 1 or 2
        fibonacci = 1;
    }
    cout << "The " << input << "th Fibonacci number is " << fibonacci << "." << endl;
    
    /* PRIME NUMBER */
    int counter = 0;
    while (counter < input) {
        for (int num = 2; num > 0; num++) { // 2 is first prime number; runs for loop for every positive integer after 2
            bool is_Prime = true;
            for (int div = 2; div <= num - 1; div++) { // checks if integer is divisible by all numbers between 2 and one less the integer --> primality check
                if (num % div == 0) { // if integer is divisible by a number that is not itself or 1, then it is not a prime
                    is_Prime = false;
                    break;
                }
            }
            if (is_Prime) { // increment on counter
                counter++;
            }
            if (counter == input) {
                cout << "The " << input << "th prime number is " << num << "." << endl;
                break;
            }
        }
    }
    
    return 0;
}
