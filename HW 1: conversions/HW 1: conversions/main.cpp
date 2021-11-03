#include <iostream>
#include <string>
using namespace std;

int main () {
    
    /* USER INPUTS MILES*/
    cout << "How many miles?" << endl;
    double user_mile = 0.;
    cin >> user_mile;
    
    
    /* CONVERSION FROM MILES TO KILOMETERS */
    const double KILOMETERS_IN_A_MILE = 1.609; // 1 mile = 1.609 kilometers
    double answer_for_mile_to_kilometer = 0.;
    answer_for_mile_to_kilometer = user_mile * KILOMETERS_IN_A_MILE; // conversion formula for miles to kilometers
    
    cout << user_mile << " miles is " << answer_for_mile_to_kilometer << " kilometers." << endl;
    
    
    /* USER INPUTS KILOMETERS */
    cout << "How many kilometers?" << endl;
    double user_kilometer = 0.;
    cin >> user_kilometer;
    
    
    /* CONVERSION FROM KILOMETERS TO MILES */
    const double MILES_IN_A_KILOMETER = 0.621; // 1 kilometer = 0.621 miles
    double answer_for_kilometer_to_mile = 0.;
    answer_for_kilometer_to_mile = user_kilometer * MILES_IN_A_KILOMETER; // conversion formula for kilometers to miles
    
    cout << user_kilometer << " kilometers is " << answer_for_kilometer_to_mile << " miles." << endl;
    
    
    /* USER INPUTS STANDARD TIME */
    cout << "Please enter a time in 12-hour format. Do not use a colon and separate by spaces." << endl;
    cout << "Example input: ''3 14 PM''. Please make sure to capitalize AM/PM." << endl;
    int user_hour = 0;
    int user_minute = 0;
    string user_am_pm;
    cin >> user_hour >> user_minute >> user_am_pm;


    /* CONVERSION FROM STANDARD TO MILITARY TIME */
    
        // condition_1 and condition_2 and condition_3 refer to qualities of user's input of the time
    
    bool condition_1 = 0;
    condition_1 = (user_am_pm == "PM"); // If user inputs PM, then true or 1. If user inputs AM, then false or 0.
        // Will be multiplied by 12 and then added to user's input.
        //This will allow PM hours to be added by 12 to fulfill military time.
    
    bool condition_2 = 0;
    condition_2 = (user_hour == 12 && user_am_pm == "AM"); // If user does input 12 AM, then true or 1.
        // Will be multipled by 12 and then subtracted from user's input after condition_1's operation.
        // This will allow user's input, if 12 AM, to go down to hour 00, which is the military time equivalent of 12 AM.
    
    bool condition_3 = 0;
    condition_3 = (user_hour == 12 && user_am_pm == "PM"); // If user does input 12 PM, then true or 1.
        // Will be multiplied by 12 and then subtracted from user's input after condition_1 and condition_2 operations.
        // If user input 12 PM, 12 will already be raised to 24 as a result of condition_1.
        // Operation of condition_3 will bring it back to 12 so 12 PM can be represented as hour 12 on military time.
    
    int new_military_hour = 0;
    new_military_hour = user_hour + (condition_1 * 12) - (condition_2 * 12) - (condition_3 * 12);
    
    cout << "The military time is: " << new_military_hour << user_minute << endl;
    
    
    /* USER INPUTS MILITARY TIME */
    cout << "Please enter a time in military format. Example input: ''1514''." << endl;
    int user_military_time;
    cin >> user_military_time;
    
    
    /* CONVERSION FROM MILITARY TO STANDARD TIME */
    int new_standard_hour;
    new_standard_hour = user_military_time / 100; // takes the military hour from user input
    
    // condition_a and condition_b refer to the qualities of new_standard_hour, which is the military hour of the the time that user input
        bool condition_a;
        condition_a = (user_military_time < 100); // If user inputs any time before 0100, then true or 1.
            // Will be multiplied by 12 and added to new_standard_hour.
            // This will allow hour 00 to be converted to 12.
        
        bool condition_b; // If user inputs any time after 1259, then true or 1.
        condition_b = (user_military_time >= 1300);
            // Will be multiplied by 12 and subtracted from new_standard_hour.
            // This will allow hour 13-23 to be converted to 1-11.
    
    new_standard_hour = new_standard_hour + (condition_a * 12) - (condition_b * 12);
    
    int new_standard_minute;
    new_standard_minute = user_military_time % 100;
    
    bool new_am_pm;
    new_am_pm = (user_military_time >= 1200); // military time that is greater or equal to 1200 is considered PM in standard time
        // 1 would mean PM, 0 would mean AM
    cout << boolalpha; // will print true/false instead of 1/0
    
    cout << "The twelve-hour time is: " << new_standard_hour << " " << new_standard_minute << " (PM = " << new_am_pm << ")." << endl;

    return 0;
}

