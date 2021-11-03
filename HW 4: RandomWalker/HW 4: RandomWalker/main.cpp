#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main () {
    
    // User inputs
    cout << "Lower Limit: ";
    double lower_limit = 0;
    cin >> lower_limit;
    
    cout << "Upper Limit: ";
    double upper_limit = 0;
    cin >> upper_limit;
    
    cout << "Start point: ";
    double start = 0;
    cin >> start;
    
    cout << "Number of Trials: ";
    double trial_number;
    cin >> trial_number;
    
    
    srand(time(0)); // ensures random number is produced
    double win = 0; // counts number of wins
    double loss = 0; // counts number of losses
    for (double i = 0; i <= trial_number; ++i) {
        double position = start; // initial position is user's starting point
        while ((position > lower_limit) && (position < upper_limit)) { // when user's position is between the lower and upper limit
            if (rand() % 2 == 0) { // if number is even, then heads
                ++position;
            }
            else {// if number is odd, then tails
                --position;
            }
        }
        if (position == upper_limit) { // if position reaches upper limit, add to win counter
            ++win;
        }
        else { // if position reaches lower limit, add to loss counter
            ++loss;
        }
    }
    
    double win_probability = win / trial_number; // probability is win divided by trial number
    // static cast used to ensure probability shows as decimal
    
    cout << endl << "Estimated win probability: " << win_probability << endl;
        
    return 0;
}
