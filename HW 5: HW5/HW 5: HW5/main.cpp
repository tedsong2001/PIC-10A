#include <iostream>
using namespace std;
#include<string>
#include<vector>
#include <cassert>



/**
 Computes area of rectangle
 @param length user's x value
 @param width user's y value
 @return the area of rectangle, using the user's input
 */
double area(double length, double width) { // length is x, width is y

    assert (length >= 0); // makes sure length is a positive value
    assert (width >= 0); // makes sure width is positive value
    double area_of_rectangle = length * width; // area is length * width

    return area_of_rectangle;// returns the area of the rectangle
}


/**
 Finds the longer of the user's words (string)
 @param str1 user's 1st word
 @param str2 user's 2nd word
 @return the longer word (string)
 */
string longest(string str1, string str2) {

    if (str1.length() >= str2.length()) return str1; // if 1st word is longer than or the same length as 2nd word, then 1st word is returned

    return str2; // if 2nd word is longer, then 2nd word is returned
}


/**
 Finds the longer of the user's words (string)
 @param str1 user's 1st word
 @param str2 user's 2nd word
 @return the shorter word (string)
 */
string shortest(string str1, string str2) {

    //YOUR CODE HERE
    if (str1.length() < str2.length()) return str1; // if 1st word is shorter than 2nd word, then 1st word is returned
    
    return str2; // if 2nd word is shorter than or the same length as 1st word, then 2nd word is returned
}

/**
Swaps the values of 2 variables
@param variable1 the first variable subject to swapping
@param variable2 the second variable subject to swapping
*/
void swap(double& variable1, double& variable2) {

    double temp = variable1; // assigns value variable1 to a temporary variable
    variable1 = variable2; // assigns value of variable2 to variable1
    variable2 = temp; // assigns value of the temporary variable to variable2, thus swapping the values of 2 original variables
}

/**
 Rearranges user's numbers, from least to greatest
 @param num1 first number of a list
 @param num2 second number of a list
 @param num3 third number of a list
 */
void sort3(double& num1, double& num2, double& num3) {

    if (num1 > num2) { // if 1st number is greater than 2nd number, then the values are swapped
        swap(num1, num2);
    }
    if (num1 > num3) { // after swap, if 1st number is greater than 3rd number, then the values are swapped
        swap(num1, num3);
    }
    if (num2 > num3) { // after swap, if 2nd number is greater than 3rd number, then the values are swapped
        swap(num2, num3);
    }
    // now the values are arranged from least to greatest
}


/**
prints a vector
@param v the vector we are printing
*/
void print(vector<double> v) {
    size_t N = v.size();
    cout << "<";
    for (size_t i = 0; i < N; ++i) {
        cout << v[i];
        if (i < N - 1) {
            cout << ',';
        }
    }
    cout << ">";
}


/**
 Reverses the order of the user's list of numbers
 @param values the list of the user's numbers
 */
void reverse(vector<double>& values) {
    
    for (int i = 0; i < values.size() / 2; i++) { // swaps values until halfway point of the vector so that values are not re-swapped to their original positions
        swap(values[i], values[values.size() - 1 - i]); // swaps i-th value and the i-th to last value
        // Ex. the 3rd value in the vector will be swapped with the 3rd to last value in the vector
        // By the end of this loop, the elements of the vector will be in the reverse order of the original
    }
}





// DO NOT EDIT THE MAIN BODY
// while working, it may be helpful to comment out the lines that actually call the functions
// (search for the word helpful)
// if you do this, make sure to uncomment them when you are done
// when you are done, the main body should be exactly the same as when you started


int main() {

    //The user picks which function to run
    cout << "Please enter 1, 2, 3, or 4. ";
    int prob;
    cin >> prob;



    if (prob == 1) {

        //ask user for length and width
        cout << "Please enter the length and width of a rectangle. ";
        double x, y;
        cin >> x >> y;

        //tell user the area of the rectangle
        cout << "The area of a rectangle with length " << x << " and width " << y << " is " << area(x, y);
        //it might be helpful to comment out the line above while testing your code
        //make sure to uncomment it when you are done

    }
    else if (prob == 2) {

        // ask user for two words
        cout << "Please enter two words. ";
        string word1, word2;
        cin >> word1 >> word2;

        //tell the user which word is longer
        cout << longest(word1, word2) << " is at least as long as " << shortest(word1, word2);
        //it might be helpful to comment out the line above while testing your code
        //make sure to uncomment it when you are done

    }
    else if (prob == 3) {
        // ask user for three numbers
        cout << "Please enter 3 numbers separated by spaces." << endl;
        double x1, x2, x3;
        cin >> x1 >> x2 >> x3;

        // sort the numbers and report them back to the user
        sort3(x1, x2, x3);
        //it might be helpful to comment out the line above while testing your code
        //make sure to uncomment it when you are done

        cout << "Your sorted numbers are " << x1 << " " << x2 << " " << x3 << endl;
    }
    else if (prob == 4) {

        //ask the user for numbers, store them in a vector
        cout << "Please enter some numbers. Type x to quit." << endl;
        double x;
        vector <double> v;
        while (true) {
            cin >> x;
            if (cin) {
                v.push_back(x);
            }
            else {
                break;
            }
        }

        //tell the user the vector
        cout << "Your vector is: ";
        print(v);

        //reverese the vector and print it again
        reverse(v);
        //it might be helpful to comment out the line above while testing your code
        //make sure to uncomment it when you are done


        cout << endl << "After reversal your vector is: ";
        print(v);

    }

    else {
        cout << "Invalid input!" << endl;
    }

    return 0;
}
