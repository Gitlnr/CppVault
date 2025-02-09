#include <iostream>
#include <string>
using namespace std;

// Base Class: Vehicle
class Vehicle {
protected: // Use protected for access by derived classes
    string maker;
    string model;
    string color;
    int year;

public:
    // Constructor
    Vehicle(const string& _maker, const string& _model, const string& _color, int _year)
        : maker(_maker), model(_model), color(_color), year(_year) {}

    // Destructor
    ~Vehicle() {
        cout << "Vehicle destroyed: " << maker << " " << model << endl;
    }

    // Display basic vehicle details
    void DisplayInfo() const {
        cout << "Maker: " << maker << endl;
        cout << "Model: " << model << endl;
        cout << "Color: " << color << endl;
        cout << "Year: " << year << endl;
    }
};

// Derived Class: Car
class Car : public Vehicle {
private:
    int doorCount;

public:
    // Constructor
    Car(const string& _maker, const string& _model, const string& _color, int _year, int _doorCount)
        : Vehicle(_maker, _model, _color, _year), doorCount(_doorCount) {}

    // Destructor
    ~Car() {
        cout << "Car destroyed: " << maker << " " << model << endl;
    }

    // Display car-specific details
    void DisplayCarInfo() const {
        // Call base class function
        DisplayInfo();
        cout << "Doors: " << doorCount << endl;
    }
};

// Derived Class: Bike
class Bike : public Vehicle {
private:
    bool carrier;

public:
    // Constructor
    Bike(const string& _maker, const string& _model, const string& _color, int _year, bool _carrier)
        : Vehicle(_maker, _model, _color, _year), carrier(_carrier) {}

    // Destructor
    ~Bike() {
        cout << "Bike destroyed: " << maker << " " << model << endl;
    }

    // Display bike-specific details
    void DisplayBikeInfo() const {
        // Call base class function
        DisplayInfo();
        cout << "Carrier: " << (carrier ? "Yes" : "No") << endl;
    }
};

// Main function
int main() {
    cout << "Inheritance Demonstration:\n" << endl;

    // Creating a Car object
    Car car("Toyota", "Camry", "Red", 2020, 4);
    cout << "Car Details:" << endl;
    car.DisplayCarInfo();

    cout << endl;

    // Creating a Bike object
    Bike bike("Honda", "CBR", "Black", 2019, true);
    cout << "Bike Details:" << endl;
    bike.DisplayBikeInfo();
    cout << endl;

    return 0;
}
