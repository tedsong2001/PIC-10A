#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

int main () {
    
    /* USER INPUTS 3 SIDE LENGTHS */
    cout << "Please enter the three side lengths separated by spaces. ";
    cout << "Example input: \"5 12 13\"" << endl << endl;
    double a = 0.;
    double b = 0.;
    double c = 0.;
    
    cin >> a >> b >> c;
    
    
    /* LARGEST SIDE */
    double x = 0.;
    x = max(a , b); // gets larger number of a and b and then assigns it to x
    
    double largest_side = 0.;
    largest_side = max(x , c); // gets larger number of x and c, thereby getting largest number from user input
    
    
    /* SMALLEST SIDE */
    double y = 0.;
    y = min(a , b); // gets smaller number of a and b and then assigns it to y
    
    double smallest_side = 0.;
    smallest_side = min(y , c); // gets smaller number of y and c, thereby getting smaller number from user input
    
    
    /* MIDDLE SIDE */
    double second_largest_side = 0.;
    second_largest_side = (a + b + c) - largest_side - smallest_side; // total - min - max = middle value
    
    
    /* RIGHT TRIANGLE CONFIRMATION */
    const double EPSILON = 1e-9;
    const double SQUARED = 2;
    
    bool right_triangle_confirmation;
    right_triangle_confirmation = ( abs( pow(smallest_side , SQUARED) + pow(second_largest_side , SQUARED) - pow(largest_side , SQUARED) ) <= EPSILON); // pythagorean theorem
    
    
    /* OUTPUT */
    const int WIDTH = 23;
    
    cout << endl << setw(WIDTH) << left << "Largest side: " << largest_side << endl;
    cout << setw(WIDTH) << left << "Second largest side: " << second_largest_side << endl;
    cout << setw(WIDTH) << left << "Smallest side: " << smallest_side << endl << endl;
    
    cout << boolalpha;
    cout << "Right triangle: " << right_triangle_confirmation << endl;
    
    return 0;
}
