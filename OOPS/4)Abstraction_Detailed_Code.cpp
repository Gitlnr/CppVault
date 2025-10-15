/*Key Concepts in Abstraction
Abstract Classes: An abstract class is a class that cannot be instantiated directly. 
It is typically used as a base class. An abstract class may contain pure virtual functions (functions that are declared but no definition in the abstract class), 
and any class derived from an abstract class must implement these functions.

Pure Virtual Functions: A pure virtual function is a function that is declared in the base class but has no definition. 
It is marked by = 0 in the function declaration. This enforces that any derived class must provide an implementation of that function.

If a pure virtual function exists in an abstract class,
then every derived class must either:

Implement that pure virtual function,
→ then it becomes a concrete (instantiable) class.

OR

Not implement it,
→ then that derived class itself remains abstract (you cannot create objects of it).
*/

#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Vehicle {
protected:
    string maker;
    string model;
    int year;

public:
    Vehicle(string _maker, string _model, int _year)
        : maker(_maker), model(_model), year(_year) {}

    // Pure virtual function (abstract function)
    virtual void startEngine() = 0;  // Pure virtual function
    virtual void stopEngine() = 0;   // Pure virtual function

    virtual void displayInfo() const {
        cout << "Maker: " << maker << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
    
    // A function that might be inherited, but not necessarily overridden
    virtual void honk() const {
        cout << "Vehicle honking!" << endl;
    }

/*If the base class destructor is virtual, then the derived classes don’t necessarily need to have their own destructors unless they need to perform specific cleanup 
(e.g., release dynamically allocated memory or other resources).
The derived class destructor will automatically call the base class destructor if it's virtual.
*/
    virtual ~Vehicle() = default;  // Virtual destructor for proper cleanup of derived class objects
};

// Derived class: Car
class Car : public Vehicle {
private:
    int doorCount;

public:
    Car(string _maker, string _model, int _year, int _doorCount)
        : Vehicle(_maker, _model, _year), doorCount(_doorCount) {}

    void startEngine() override {
        cout << "Car engine started." << endl;
    }

    void stopEngine() override {
        cout << "Car engine stopped." << endl;
    }

    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "Doors: " << doorCount << endl;
    }
    
     void honk() const override {
        cout << "Car honking: Beep Beep!" << endl;
    }
};

// Derived class: Bike
class Bike : public Vehicle {
private:
    bool hasCarrier;

public:
    Bike(string _maker, string _model, int _year, bool _hasCarrier)
        : Vehicle(_maker, _model, _year), hasCarrier(_hasCarrier) {}

    void startEngine() override {
        cout << "Bike engine started." << endl;
    }

    void stopEngine() override {
        cout << "Bike engine stopped." << endl;
    }

    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "Carrier: " << (hasCarrier ? "Yes" : "No") << endl;
    }
};

int main() {
    // Cannot instantiate Vehicle directly because it has pure virtual functions
    // Vehicle v("Toyota", "Camry", 2021); // This would cause a compile-time error

    // Instantiate derived classes
    Vehicle* car = new Car("Toyota", "Corolla", 2021, 4);
    Vehicle* bike = new Bike("Yamaha", "R15", 2022, true);

    // Display info and start/stop engine for both vehicles
    car->displayInfo();
    car->startEngine();
    car->stopEngine();
    car->honk();        // Will call the Car's overridden honk
    cout << endl;

    bike->displayInfo();
    bike->startEngine();
    bike->stopEngine();
    bike->honk();        // Will call the Vehicle's default honk (because Bike didn't override it)

    // Clean up
    delete car;
    delete bike;

    return 0;
}
