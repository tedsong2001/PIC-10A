#include <iostream>
using namespace std;

class Car {
public:
    // Constructors
    Car(const double my_miles_per_gallon, const int my_year, double my_current_gas_level): MILES_PER_GALLON(my_miles_per_gallon), YEAR(my_year), current_gas_level(my_current_gas_level) {
        // MILES_PER_GALLON = my_miles_per_gallon;
        // YEAR = my_year;
        // current_gas_level = my_current_gas_level;
    }
    
    Car(const double my_miles_per_gallon, const int my_year): MILES_PER_GALLON(my_miles_per_gallon), YEAR(my_year), current_gas_level(0) {
        // MILES_PER_GALLON = my_miles_per_gallon;
        // YEAR = my_year;
        // current_gas_level = 0;
    }
    
    // Mutators
    /**
     Computes the current gas level after miles driven
     @param miles the number of miles driven on the car
     */
    void drive(double miles);
    
    /**
     Computes the current gas level after adding gass
     @param gas amount of gas added
     */
    void add_gas(double gas);
    
    
    // Accessors
    /**
     Getter function
     @return the miles per gallon of the car
     */
    double get_MILES_PER_GALLON() const { return MILES_PER_GALLON; }
    
    /**
     Getter function
     @return the year the car was made
     */
    int get_YEAR() const { return YEAR; }
    
    /**
     Getter function
     @return the current gas level of the car
     */
    double get_current_gas_level() const { return current_gas_level; }
    
    /**
     Compares the ages of cars
     @param other  user's second car
     @return bool, if first car is older than second car
     */
    bool is_older_than(const Car& other) const;
    
    /**
     prints car info
     */
    void print_info() const;
    
private:
    // Member variables
    const double MILES_PER_GALLON;
    const int YEAR;
    double current_gas_level;
};


int main () {
    
    Car c1(34.0, 2020, 10.2),
        c2(26.0, 2019, 15.2);
    
    cout << " Car 1: ";
    c1.print_info();
    
    cout << " Car 2: ";
    c2.print_info();
    
    
    c1.drive(102.0);
    c2.add_gas(2.7);
    
    cout << " Car 1 after drive: ";
    c1.print_info();
    
    cout << " Car 2 after adding gas: ";
        c2.print_info();
    
    cout << " Is Car 1 older than Car 2? "
        << boolalpha << c1.is_older_than(c2) << endl;
    
    return 0;
}

// Function definitions
void Car::drive(double miles) {
    double gallons_used = miles / MILES_PER_GALLON;
    current_gas_level -= gallons_used;
}

void Car::add_gas(double gas) {
    current_gas_level += gas;
}

bool Car::is_older_than(const Car& other) const {
    return (get_YEAR() < other.get_YEAR());
}

void Car::print_info() const {
    cout <<
        "\n---- Car info ----" <<
        "\n  MPG          : " << MILES_PER_GALLON <<
        "\n  YEAR         : " << YEAR <<
        "\n  Curr Gas Lvl : " << current_gas_level << "\n------------------\n" << endl;
}
