#include <iostream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;

class Country {
public:
    
    // Constructors
    Country(string country_name, int country_population, double country_area): country(country_name), population(country_population), area(country_area) {
        // population = country_population;
        // area = country_area;
        // country = country_name;
        assert(country_population > 0);
        assert(country_area > 0);
    }
    
    // Accessors
    /**
     accesses country name from private
     @return country name
     */
    string get_name() const { return country; }
    
    /**
     accesses population from private
     @return population of country
     */
    int get_population() const { return population; }
    
    /**
     accesses area from private
     @return area of country
     */
    double get_area() const { return area; }
    
    /**
     density formula
     @return density
     */
    double get_density() const;
    
    /**
     prints the population, area, and density
     */
    void print_info() const;
    
    
private:
    // Member variables
    int population;
    double area;
    string country;
};

/**
 compares the density of countries
 @param country_list the vector of countries (with population and area info)
 @return the country with the highest density
 */
Country most_dense(vector<Country> country_list) {
    double greatest_density = 0.;
    int num = 0; // holds the element number that contains the most dense country in the vector
    for (int i = 0; i < country_list.size(); ++i) {
        if (country_list[i].get_density() > greatest_density) {
            greatest_density = country_list[i].get_density(); // updates the value of the highest density of all the countries
            num = i; // assigns the element number that contains the most dense country to variable num
        }
    }
    return country_list[num];
}

int main() {
    
    Country c1("Country A", 20, 1.0), c2("USA", 15, 1.5), c3("Some other country", 1000, 2.0);
    vector<Country> C = { c1, c2, c3 };
    
    for (size_t i = 0, N = C.size(); i < N; ++i) {
        C[i].print_info();
        cout << '\n';
    }
    cout << "-------------------------------------" << endl;
    Country md = most_dense(C);
    cout << "The most dense country's population: " << md.get_population() << '\n'
        << "                         area      : " << md.get_area() << '\n'
        << "                         density   : " << md.get_population() / md.get_area() << endl;
    
    return 0;
}

// Function declarations

double Country::get_density() const {
    return get_population() / get_area(); // density formula
}

void Country::print_info() const {
    cout << country << ":\n"
        << "  population: " << population << '\n'
        << "  area      : " << area << '\n'
        << "  density   : " << get_density() << endl;
}
