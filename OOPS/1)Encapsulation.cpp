/* Encapsulation in C++

Encapsulation is one of the four fundamental principles of Object-Oriented Programming (OOP).
It refers to a wrapping  data (variables) and methods (functions) in a single unit, called a class.
Encapsulation also involves restricting direct access to some of the object's components, which is often achieved by making use 
of access specifiers like private, protected, and public.

Key benefits of encapsulation:
1. Data hiding: Protects the internal state of an object and prevents unintended interference.
2. Code modularity: Enhances code maintainability and reduces complexity.
3. Controlled access: You can control how the data in an object is accessed or modified using getter and setter methods.

Constructors and Destructors
Note : Usually complier automatically creates a constructor, it is called when a object is created.
      -The memory is allocated when the constructor is called ,not when class is created.
1. Constructor:
   - A constructor is a special member function that initializes an object when it is created.
   - It has the same name as the class and no return type.
   - Constructors can be overloaded.
2. Destructor:
   - A destructor is a special member function that cleans up when an object goes out of scope or is deleted.
   - It has the same name as the class, prefixed with a tilde (`~`), and takes no arguments.  */ 

// Example of Encapsulation with Constructor and Destructor
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    // Constructor
    Student(string studentName, int studentAge) {
        name = studentName;
        age = studentAge;
        cout << "Constructor called for: " << name << endl;
    }

    // Getter for name
    string getName() const {
        return name;
    }

    // Setter for name
    void setName(string newName) {
        name = newName;
    }

    // Getter for age
    int getAge() const {
        return age;
    }

    // Setter for age
    void setAge(int newAge) {
        age = newAge;
    }

    // Destructor
    ~Student() {
        cout << "Destructor called for: " << name << endl;
    }
};

int main() {
    Student s1("John", 20);
    cout << "Name: " << s1.getName() << ", Age: " << s1.getAge() << endl;

    s1.setName("Johnny");
    s1.setAge(21);
    cout << "Updated Name: " << s1.getName() << ", Updated Age: " << s1.getAge() << endl;

    return 0; //When main() reaches return 0; it signals the end of the function. The destructor is called .
}

// Types of Constructors
/*
1. Default Constructor:
   - Automatically provided by the compiler if no constructor is explicitly defined.

     class Example {
     public:
         Example() {
             cout << "Default constructor called!" << endl;
         }
     };
      Example obj; // Calls the default constructor

2. Parameterized Constructor:
   - Accepts arguments to initialize object data.
   - Example: 
     Example(int x) {
         cout << "Parameterized constructor, x = " << x << endl;
     }

3. Copy Constructor:
   - Creates a new object as a copy of an existing object.

 Shallow Copy vs Deep Copy

  - Shallow Copy: Copies the values of data members as they are (including pointers). Both objects share the same memory for the pointer.
  - Use Case: Quick copying when no dynamic memory allocation is involved.
  - Problem: Modifying one affects the other.

  - Deep Copy: Copies the values and allocates new memory for dynamic data, ensuring independent objects.
  - Use Case: Used when objects involve dynamically allocated memory.
*/
// Example: Shallow Copy vs Deep Copy

#include <iostream>
#include <cstring>
using namespace std;

class CopyExample {
private:
    char* data;

public:
    // Parameterized Constructor
    CopyExample(const char* initData) {
        data = new char[strlen(initData) + 1]; //forgetting to add +1, the null terminator may overwrite some other memory, causing undefined behavior.
        strcpy(data, initData);
    }

    // Shallow Copy Constructor
    CopyExample(const CopyExample& other) {
        data = other.data; // Just copies the pointer (shallow)
    }

    // Deep Copy Constructor
    CopyExample(const CopyExample& other, bool deepCopy) {
        if (deepCopy) {
            data = new char[strlen(other.data) + 1];// Allocates new memory and +1 for null terminator 
            strcpy(data, other.data); //copies the value from other.data to data
        }
    }

    void display() {
        cout << "Data: " << data << endl;
    }

    ~CopyExample() {
        delete[] data; //new[] is used to allocate arrays dynamically so while dellocation ,delete the array of characters
    }
};

int main() {
    CopyExample shallow("Hello");
    CopyExample deep("World", true);

    shallow.display();
    deep.display();

    return 0;
}

/* Additional Note :
A C-style string ends with a special null character ('\0'), which marks the end of the string.
This null character is not part of the visible content but is essential for string functions like strlen or strcmp to work correctly.
Ex:
const char* initData = "Hello";
size_t length = strlen(initData); // Returns 5, does not include '\0'

// Correct memory allocation:
char* data = new char[length + 1]; // +1 ensures space for '\0'
strcpy(data, initData); // Copies "Hello" into data, including the '\0'

// Incorrect memory allocation:
char* dataWithoutNull = new char[length]; // No space for '\0'
strcpy(dataWithoutNull, initData); // Undefined behavior, as '\0' will overflow

Ex:
char data[] = "Hello";  // Compiler automatically adds '\0'
char data[6] = {'H', 'e', 'l', 'l', 'o', '\0'};  // Correct way
char data[5] = {'H', 'e', 'l', 'l', 'o'};  // InCorrect way //causes overflow
char data[5], valid indices are 0 to 4.
*/
// Destructor with Deletion Example

#include <iostream>
using namespace std;

class Test {
private:
    int* ptr;

public:
    Test(int val) {
        ptr = new int(val);
        cout << "Memory allocated, value: " << *ptr << endl;
    }

    ~Test() {
        delete ptr; //allocated memory using new (not new[]), so you must use delete (not delete[]
     /* 
      Allocation Type	Correct Deallocation
      ptr = new int(10);	delete ptr;
      ptr = new int[10];	delete[] ptr;
      */
          cout << "Memory deallocated!" << endl;
    }
};

int main() {
    Test obj(100);
    return 0; // Destructor is called automatically
}
