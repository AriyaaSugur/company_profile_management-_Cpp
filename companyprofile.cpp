#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Class to hold CEO's information
class CEO {
public:
    string ceo_name;
    CEO(string name) : ceo_name(name) {}
};

// Class to hold Country's information
class Country {
public:
    string country_name;
    Country(string name) : country_name(name) {}
};

// Class to hold Sector's information
class Sector {
public:
    string sector_name;
    Sector(string name) : sector_name(name) {}
};

// Class to hold Company's information
class Company {
public:
    string name;
    double turnover;
    int year_of_establishment;
    string headquarters_location;
    CEO* ceo;
    Country* country;
    Sector* sector;

    // Constructor to initialize all data including pointers
    Company(string n, double t, int y, string h, CEO* c, Country* co, Sector* s) :
        name(n), turnover(t), year_of_establishment(y),
        headquarters_location(h), ceo(c), country(co), sector(s) {}

    // Destructor to clean up dynamically allocated memory
    ~Company() {
        delete ceo;
        delete country;
        delete sector;
    }

    // Function to display the company profile
    void displayProfile() const {
        cout << "|" << setw(20) << left << name
             << "|" << setw(20) << left << turnover
             << "|" << setw(20) << left << year_of_establishment
             << "|" << setw(25) << left << headquarters_location
             << "|" << setw(20) << left << ceo->ceo_name
             << "|" << setw(20) << left << country->country_name
             << "|" << setw(20) << left << sector->sector_name << "|" << endl;
    }
};

// Function to display the company profiles in a tabular format
void displayTable(const vector<Company*>& companies) {
    // Printing table headers with vertical lines
    cout << "+" << setw(20) << left << "Company Name"
         << "+" << setw(20) << left << "Turnover (in millions)"
         << "+" << setw(20) << left << "Year of Establishment"
         << "+" << setw(25) << left << "HQ Location"
         << "+" << setw(20) << left << "CEO Name"
         << "+" << setw(20) << left << "Country"
         << "+" << setw(20) << left << "Sector"
         << "+" << endl;

    // Printing the separator line
    cout << "+--------------------+--------------------+--------------------+--------------------------+--------------------+--------------------+--------------------+" << endl;

    // Printing each company profile with vertical lines
    for (const auto& company : companies) {
        company->displayProfile();
    }

    // Printing the bottom separator line
    cout << "+--------------------+--------------------+--------------------+--------------------------+--------------------+--------------------+--------------------+" << endl;
}

int main() {
    int n;
    cout << "Enter the number of companies: ";
    cin >> n;
    cin.ignore();  // Clear the input buffer

    vector<Company*> companies;

    // Taking input for each company
    for (int i = 0; i < n; ++i) {
        string name, ceo_name, country_name, sector_name, headquarters_location;
        double turnover;
        int year_of_establishment;

        cout << "\nEnter details for company " << i + 1 << ":\n";
        cout << "Company Name: ";
        getline(cin, name);
        cout << "Turnover (in millions): ";
        cin >> turnover;
        cout << "Year of Establishment: ";
        cin >> year_of_establishment;
        cin.ignore();  

        cout << "Headquarters Location: ";
        getline(cin, headquarters_location);
        cout << "CEO Name: ";
        getline(cin, ceo_name);
        cout << "Country: ";
        getline(cin, country_name);
        cout << "Sector: ";
        getline(cin, sector_name);

        // Creating objects for CEO, Country, and Sector classes
        CEO* ceo = new CEO(ceo_name);
        Country* country = new Country(country_name);
        Sector* sector = new Sector(sector_name);

        // Creating a company object dynamically and adding it to the list
        companies.push_back(new Company(name, turnover, year_of_establishment, headquarters_location, ceo, country, sector));
    }

    // Displaying the company profiles with vertical lines
    displayTable(companies);

    // Deleting dynamically allocated memory
    for (auto& company : companies) {
        delete company;
    }

    return 0;
}
