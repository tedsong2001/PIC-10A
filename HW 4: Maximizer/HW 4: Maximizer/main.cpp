#include <iostream>
#include <cmath>
using namespace std;

int main () {
    
    // User inputs
    cout << "Left end point: ";
    double left_endpoint = 0.;
    cin >> left_endpoint;
    
    cout << "Right end point: ";
    double right_endpoint = 0.;
    cin >> right_endpoint;
    
    cout << "Coefficients: ";
    double a = 0.;
    double b = 0.;
    double c = 0.;
    double d = 0.;
    cin >> a >> b >> c >> d;
    
    cout << "Grid size: ";
    double grid_size;
    cin >> grid_size;
    
    // Finding largest value in cubic polynomial
    double x = left_endpoint;
    double largest = (a * pow(x, 3)) + (b * pow(x, 2)) + (c * x) + d; // Sets initial value as largest value
    double y = 0.;
    while (x <= right_endpoint) { // Performs while loop until x reaches user's left endpoint
        y = (a * pow(x, 3)) + (b * pow(x, 2)) + (c * x) + d; // Calculates cubic polynomial with user's input
        if (y >= largest) { // If y is greater than the previous largest value, then y is assigned as the largest value
            largest = y;
        }
        x = x + grid_size; // Adds grid size and then repeats the while loop
    }
        
    // Outputs largest value of polynomial in a sentence
    cout << endl << "The largest value of " << a << "*x^3+" << b << "*x^2+" << c << "*x+" << d << " on [" << left_endpoint << "," << right_endpoint << "] is " << largest << "." << endl;
    
    return 0;
}
