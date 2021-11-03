#include <iostream>
using namespace std;

/**
 Finds if two arrays have the same distinct elements
 @param a first array
 @param a_size size of first array
 @param b second array
 @param b_size size of second array
 @return true or false, if both arrays have the same distinct elements
 */
bool same_items(int a[], size_t a_size, int b[], size_t b_size);

int main() {
    
    const int SIZE1 = 4;
    int num1[SIZE1] = { 6, 6, 6, 5 };
    
    const int SIZE2 = 5;
    int num2[SIZE2] = { 6, 6, 6, 6, 6 };
    
    cout << boolalpha << same_items(num1, SIZE1, num2, SIZE2);
    
    return 0;
}

// Function Declarations

bool same_items(int a[], size_t a_size, int b[], size_t b_size) {
    for (size_t i = 0; i < a_size; ++i) { // for loop, comparing first array to second array
        int temp = a[i];
        int j = 0;
        while (j < b_size) {
            if ((j == b_size - 1) && (b[j] != temp)) { // if a number in first array is not present in second array
                return false;
            }
            else if (b[j] == temp) { // if a number in first array is present in second array
                break; // breaks the while loop, which moves onto the next number in the first array
            }
            else { // if a number in first array is not the same as a number in the second array
                ++j; // increments, moving onto the next number in the second array
            }
        }
    }
    for (size_t i = 0; i < b_size; ++i) { // for loop, comparing second array to first array
        int temp = b[i];
        int j = 0;
        while (j < a_size) {
            if ((j == a_size - 1) && (a[j] != temp)) { // if a number in second array is not present in first array
                return false;
            }
            else if (a[j] == temp) { // if a number in second array is present in first array
                break; // breaks the while loop, which moves on the next number in the second array
            }
            else { // if a number in second array is not the same as a number in the second array
                ++j; // increments, moving onto the next number in the second array
            }
        }
    }
    return true;
}
