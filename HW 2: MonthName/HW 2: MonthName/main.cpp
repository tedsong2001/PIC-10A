#include <iostream>
#include <string>
using namespace std;

int main () {
    
    /* USER INPUT */
    cout << "Please enter a word (5-letter minimum)." << endl;
    string word;
    cin >> word;
    
    cout << "Please enter a month number (1-12)." << endl;
    int month_number = 0;
    cin >> month_number;
    
    cout << "Please enter 1, 2, or 3." << endl;
    int number = 0;
    cin >> number;
    
    
    string month_list = "          January   February  March     April     May       June      July      August    September October   November  December  ";
    
    /* MONTH NAME */
    int month_placement = 10 * month_number;
    // Multiplied by 10 because there is a month name in every 10 characters.
    const int CHARACTERS_PER_MONTH = 10; // there are 10 characters per month
    cout << "Month: " << month_list.substr(month_placement , CHARACTERS_PER_MONTH) << endl;
    
    /* LETTERS OF THE MONTH */
    cout << "First " << number << " letter(s) of your month: " << month_list.substr(month_placement , number) << endl; // prints first letters of month, based on user's number
    
    /* LETTERS OF THE USER'S WORD */
    cout << "Word: " << word << endl;
    cout << "Last " << number << " letters(s) of your word: " << word.substr(word.length() - number) << endl;
    
    return 0;
}
