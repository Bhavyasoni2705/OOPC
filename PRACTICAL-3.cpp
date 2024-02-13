#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class CarCatalog {
private:
    struct Car {
        string modelName;
        string fuelType;
        float showroomPrice;
        float mileage;
        string transmission;
        float tankCapacity;
        int seating;
        string airbags;
    };

    const int numCars = 7;
    Car tataCars[7];

public:

    CarCatalog() {
        tataCars[0] = {"TIAGO", "CNG", 500000, 25, "Manual", 35, 5, "YES"};
        tataCars[1] = {"PUNCH", "Diesel", 1050000, 20, "AMT", 37, 5, "YES"};
        tataCars[2] = {"SAFARI", "Diesel", 2000000, 15, "AMT", 70, 7, "YES"};
        tataCars[3] = {"HARRIER", "Diesel", 1800000, 18, "AMT", 60, 5, "YES"};
        tataCars[4] = {"TIGOR", "Petrol", 600000, 22, "Manual", 40, 5, "YES"};
        tataCars[5] = {"ALTROZ", "Petrol", 800000, 20, "Manual", 42, 5, "YES"};
        tataCars[6] = {"NEXON", "Electric", 900000, 20, "AMT", 45, 5, "YES"};
    }

    void displayCarModelNames() const {
        cout << "\nLIST OF TATA CARS:\n";
        for (int i = 0; i < numCars; ++i) {
            cout << "(" << i + 1 << ") " << tataCars[i].modelName << endl;
        }
    }

    void displayCarDetails(int carChoice) const {
        if (carChoice < 1 || carChoice > numCars) {
            cout << "Invalid car choice.\n";
            return;
        }
        carChoice--;

        cout << setw(10) << "MODEL" << setw(10) << "FUEL" << setw(15) << "PRICE(LAKHS)" << setw(15) << "MILEAGE" << setw(20) << "TRANSMISSION" << setw(20) << "TANK CAPACITY" << setw(20) << "SEATING CAPACITY" << setw(10) << "AIRBAGS\n";
        cout << setw(10) << tataCars[carChoice].modelName << setw(10) << tataCars[carChoice].fuelType << setw(15) << tataCars[carChoice].showroomPrice / 100000 << setw(15) << tataCars[carChoice].mileage << setw(20) << tataCars[carChoice].transmission << setw(20) << tataCars[carChoice].tankCapacity << setw(20) << tataCars[carChoice].seating << setw(10) << tataCars[carChoice].airbags << endl;
    }

    void displayCarsByFuelType(const string& fuelType) const {
        cout << "\nLIST OF TATA CARS FOR FUEL TYPE: " << fuelType << endl;
        cout << setw(10) << "MODEL" << setw(10) << "FUEL" << setw(15) << "PRICE(LAKHS)" << setw(15) << "MILEAGE" << setw(20) << "TRANSMISSION" << setw(20) << "TANK CAPACITY" << setw(20) << "SEATING CAPACITY" << setw(10) << "AIRBAGS\n";
        for (int i = 0; i < numCars; ++i) {
            if (tataCars[i].fuelType == fuelType) {
                cout << setw(10) << tataCars[i].modelName << setw(10) << tataCars[i].fuelType << setw(15) << tataCars[i].showroomPrice / 100000 << setw(15) << tataCars[i].mileage << setw(20) << tataCars[i].transmission << setw(20) << tataCars[i].tankCapacity << setw(20) << tataCars[i].seating << setw(10) << tataCars[i].airbags << endl;
            }
        }
    }

    void displayCarsByPriceRange(float minPrice, float maxPrice) const {
        cout << "\nLIST OF TATA CARS WITHIN PRICE RANGE: " << minPrice << " - " << maxPrice << " lakhs\n";
        cout << setw(10) << "MODEL" << setw(10) << "FUEL" << setw(15) << "PRICE(LAKHS)" << setw(15) << "MILEAGE" << setw(20) << "TRANSMISSION" << setw(20) << "TANK CAPACITY" << setw(20) << "SEATING CAPACITY" << setw(10) << "AIRBAGS\n";
        for (int i = 0; i < numCars; ++i) {
            if (tataCars[i].showroomPrice >= minPrice * 100000 && tataCars[i].showroomPrice <= maxPrice * 100000) {
                cout << setw(10) << tataCars[i].modelName << setw(10) << tataCars[i].fuelType << setw(15) << tataCars[i].showroomPrice / 100000 << setw(15) << tataCars[i].mileage << setw(20) << tataCars[i].transmission << setw(20) << tataCars[i].tankCapacity << setw(20) << tataCars[i].seating << setw(10) << tataCars[i].airbags << endl;
            }
        }
    }
};

int main() {
    cout << "WELCOME TO TATA MOTORS\n";
    cout << "GET THE CAR DETAILS AS PER YOUR PREFERENCE\n";

    cout << "(1) MODEL NAME :\n";
    cout << "(2) FUEL TYPE :\n";
    cout << "(3) PRICE RANGE :\n";

    int option;
    cout << "ENTER YOUR OPTION : ";
    cin >> option;

    CarCatalog catalog;
    switch(option) {
        case 1: {
            catalog.displayCarModelNames();
            int carChoice;
            cout << "\nCHOOSE YOUR CAR TO GET DETAILS: ";
            cin >> carChoice;
            catalog.displayCarDetails(carChoice);
            break;
        }
        case 2: {
            cout << "\nFUEL TYPES:\n";
            cout << "(1) Petrol\n";
            cout << "(2) Diesel\n";
            cout << "(3) CNG\n";
            cout << "(4) Electric\n";

            int fuelChoice;
            cout << "\nCHOOSE FUEL TYPE TO GET DETAILS: ";
            cin >> fuelChoice;
            string fuelType;
            switch (fuelChoice) {
                case 1:
                    fuelType = "Petrol";
                    break;
                case 2:
                    fuelType = "Diesel";
                    break;
                case 3:
                    fuelType = "CNG";
                    break;
                case 4:
                    fuelType = "Electric";
                    break;
                default:
                    cout << "Invalid choice.\n";
                    return 1;
            }
            catalog.displayCarsByFuelType(fuelType);
            break;
        }
        case 3: {
            float minPrice, maxPrice;
            cout << "\nEnter Min Price: ";
            cin >> minPrice;
            cout << "Enter Max Price: ";
            cin >> maxPrice;
            catalog.displayCarsByPriceRange(minPrice, maxPrice);
            break;
        }
        default:
            cout << "Invalid option. Exiting.\n";
    }

    return 0;
}
