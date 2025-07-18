/*Polymorphism in C++ is achieved using virtual functions.
The main purpose of polymorphism is to allow a program to choose at runtime which method to invoke based on the actual object type*/

#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string maker;
    string model;
    string color;
    int year;

public:
    // Constructor
    Vehicle(const string& _maker, const string& _model, const string& _color, int _year)
        : maker(_maker), model(_model), color(_color), year(_year) {}

    // Virtual Destructor
    virtual ~Vehicle() {}

    // Virtual methods (for polymorphism)
    virtual void SetMaker(const string& _maker) { maker = _maker; }
    virtual void SetModel(const string& _model) { model = _model; }
    virtual void SetColor(const string& _color) { color = _color; }
    virtual void SetYear(int _year) { year = _year; }

    // Getters
    string GetMaker() const { return maker; }
    string GetModel() const { return model; }
    string GetColor() const { return color; }
    int GetYear() const { return year; }

    // Virtual method to display information (polymorphism)
    virtual void DisplayInfo() const {
        cout << "Maker: " << GetMaker() << ", Model: " << GetModel()
             << ", Color: " << GetColor() << ", Year: " << GetYear() << endl;
    }
};

class Car : public Vehicle {
private:
    int doorCount;

public:
    // Constructor
    Car(const string& _maker, const string& _model, const string& _color, int _year, int _doorCount)
        : Vehicle(_maker, _model, _color, _year), doorCount(_doorCount) {}

    // Override setters (to demonstrate polymorphism)
    void SetMaker(const string& _maker) override {
        Vehicle::SetMaker(_maker); // You can call base class setter
        cout << "Car maker is set to: " << _maker << endl;
    }

    void SetModel(const string& _model) override {
        Vehicle::SetModel(_model);
        cout << "Car model is set to: " << _model << endl;
    }

    void SetColor(const string& _color) override {
        Vehicle::SetColor(_color);
        cout << "Car color is set to: " << _color << endl;
    }

    void SetYear(int _year) override {
        Vehicle::SetYear(_year);
        cout << "Car year is set to: " << _year << endl;
    }

    // Getter for door count
    int GetDoorCount() const { return doorCount; }

    // Override DisplayInfo for Car-specific details
    void DisplayInfo() const override {
        Vehicle::DisplayInfo(); // Call base class method
        cout << "Type: Car, Doors: " << GetDoorCount() << endl;
    }
};

class Bike : public Vehicle {
private:
    bool carrier;

public:
    // Constructor
    Bike(const string& _maker, const string& _model, const string& _color, int _year, bool _carrier)
        : Vehicle(_maker, _model, _color, _year), carrier(_carrier) {}

    // Override setters (to demonstrate polymorphism)
    void SetMaker(const string& _maker) override {
        Vehicle::SetMaker(_maker); // You can call base class setter
        cout << "Bike maker is set to: " << _maker << endl;
    }

    void SetModel(const string& _model) override {
        Vehicle::SetModel(_model);
        cout << "Bike model is set to: " << _model << endl;
    }

    void SetColor(const string& _color) override {
        Vehicle::SetColor(_color);
        cout << "Bike color is set to: " << _color << endl;
    }

    void SetYear(int _year) override {
        Vehicle::SetYear(_year);
        cout << "Bike year is set to: " << _year << endl;
    }

    // Getter for carrier
    bool GetCarrier() const { return carrier; }

    // Override DisplayInfo for Bike-specific details
    void DisplayInfo() const override {
        Vehicle::DisplayInfo(); // Call base class method
        cout << "Type: Bike, Carrier: " << (GetCarrier() ? "Yes" : "No") << endl;
    }

    // Method to set the carrier (specific to Bike)
    void SetCarrier(bool _carrier) { carrier = _carrier; }
};

int main() {
    // Create a Car and a Bike using polymorphism
    Vehicle* car = new Car("Toyota", "Corolla", "Red", 2020, 4);
    Vehicle* bike = new Bike("Honda", "CBR", "Black", 2019, true);

    // Display initial vehicle info using polymorphism
    cout << "Initial Vehicle Info:\n";
    car->DisplayInfo();
    bike->DisplayInfo();

    // Using setters to modify properties (demonstrating polymorphism)
    car->SetMaker("Ford");
    car->SetModel("Mustang");
    car->SetColor("Blue");
    car->SetYear(2022);

    bike->SetColor("White");
    bike->SetYear(2020);

    // Now we can safely cast the Vehicle pointer to a Bike pointer to use SetCarrier
    //Downcast to the Bike class: Since SetCarrier is a method of the Bike class, 
    //use dynamic_cast to convert the base class pointer (Vehicle*) to a derived class pointer (Bike*).
    Bike* bikePtr = dynamic_cast<Bike*>(bike);
    if (bikePtr) {
        bikePtr->SetCarrier(false); // This works because bikePtr is now a pointer to Bike
    }

    // Display modified vehicle info after changes
    cout << "\nModified Vehicle Info (After Customer Changes):\n";
    car->DisplayInfo();
    bike->DisplayInfo();

    // Clean up dynamically allocated memory
    delete car;
    delete bike;

    return 0;
}


//Additional Note 
#include <iostream>
#include <string>
using namespace std;

// Using pass by reference
void greet(const string& name) {
    cout << "Hello, " << name << endl;
}

// Using pass by value (inefficient)
void greetValue(string name) {
    cout << "Hello, " << name << endl;
}

int main() {
    string name = "Alice";
    
    greet(name);      // Efficient: No copy
    greetValue(name); // Inefficient: Copies 'name' into the function
}

What Happens in Pass by Reference?
When you pass a variable by reference (&), the function does not create a new copy. Instead, it works directly on the original memory.

✅ Example: Pass by Reference (Efficient)
#include <iostream>
using namespace std;

void modify(int& x) {  
    x = x * 2;  // Modifies the original variable directly
}

int main() {
    int num = 10;
    modify(num);  
    cout << "Modified num: " << num << endl;  // ✅ Prints: 20 (original memory changed)
    return 0;
}

❌ What Happens in Pass by Value?
If you pass a variable by value, a copy is made, and changes do not affect the original variable.

❌ Example: Pass by Value (Inefficient)
void modify(int x) {  
    x = x * 2;  // Only modifies the copied value (original remains unchanged)
}

int main() {
    int num = 10;
    modify(num);
    cout << "num: " << num << endl;  // ❌ Prints: 10 (original is NOT changed)
}
🚨 Problem: num remains 10 because modify(int x) worked on a separate copy.

Method	                     Copies Memory?	    Can Modify Original?	Efficient?
Pass by Value (int x)	      ✅ Yes	             ❌ No	               ❌ No
Pass by Reference (int& x)	  ❌ No	                 ✅ Yes	               ✅ Yes
