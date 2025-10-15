#include <iostream>
using namespace std;

//used for pointer to pointer
//When you want to modify the actual pointer (not just the value it points to), you must use a pointer to a pointer (int **ptr)
//*ptr = &num;` **changes the address stored in the original pointer (`p`)**,
//so now `p` points to a **new memory location (`num`)**.
void update( int** ptr){
  static int num = 50;
  *ptr = &num; //ptr points to num
}
//Only gets a copy of p, NOT modifying original p
void updatePtr(int* ptr){
  static int num = 50;
  ptr = &num; //ptr still points to x, not num
}
int main() {

///////////////Pointer Basics/////////////////////////////////
    int  a= 10;
    int *p ;
    p = &a;
    cout<<"Pointer Basics"<<endl;
    cout <<"*p value is "<<*p<<endl; //output : 10
    cout <<"a value is "<<a<<endl;  //output : 10
    cout <<"&a value is "<<&a<<endl; //output : address of variable a
    cout <<"p value is "<<p<<endl; //output : holds the address of variable a //`p` stores the address of `a`.
    cout <<"&p value is "<<&p<<endl; //output : address of pointer p  `&p` gives the memory address of `p` itself, which is stored at a different location in memory.
    cout<<endl;

  ///////////////Arithmetic Pointer/////////////////////////////////
    int arr[] = {10, 20, 30, 40};
    int *pp = arr;
     cout<<"Arithmetic Pointer"<<endl;
    cout << "pp: " << pp<< endl;           // Address of the first element (e.g., 0x7ffee3b9a660) 
    cout << "*pp: " << *pp << endl;         // 10  //*p gives the value at that address (arr[0] = 10).
    cout << "*(pp+1): " << *(pp+1) << endl; // 20
    cout << "pp[2]: " << pp[2] << endl;     // 30 //pp[2] is same as *(pp+2)
    cout << "*(pp+3): " << *(pp+3) << endl; // 40
    cout << "&arr[3] - &arr[2]: " << &arr[3] - &arr[2] << endl; //1 (&arr[3] givesthe address of arr[3],so 3-2 =1)
    cout << "&arr[3] - arr: " << &arr[3] - arr <<endl; // 3 (difference in array indices)( arr gives teh base address that is 0 ,3-0 = 3)
    cout <<endl;

  ///////////////Pointer to Pointer/////////////////////////////////
    int x = 10;
    int *ptr = &x;

    cout<<"Pointer to Pointer"<<endl;  // Output: 10 (p points to x)
    cout << "Before Update ptr: " << *ptr <<endl; // `ptr` now points to `num` instead of `x`
    update(&ptr); //always pass the address ,you cant passs *ptr
    cout << "After Update ptr: " << *ptr <<endl; // Output: 50 (p now points to `num`)
    cout <<endl;

  int *ptr1 = &x;
    cout << "Modifies the local copy of ptr, NOT the original pointer" <<endl;
    cout << "Before: " << *ptr1 << endl;  // Output: 10
    updatePtr(ptr1); // Passing ptr1, but it's just a copy!
    cout << "After: " << *ptr1 << endl;   // Output: 10 (Unchanged!)

  ///////////////Pointer & const////////////////////////////////
/*
int a = 10, b = 20;

const int *p1 = &a;  // p1 is a pointer to a constant int (value can't be modified)
int *const p2 = &a;  // p2 is a constant pointer to an int (address can't be changed)
const int *const p3 = &a;  // p3 is a constant pointer to a constant int (neither can change)

// --- Test Cases ---
*p1 = 30;  // ❌ Error: Cannot modify value through a pointer to const
p1 = &b;   // ✅ Valid: Can change what p1 points to

*p2 = 40;  // ✅ Valid: Can modify value through p2
p2 = &b;   // ❌ Error: Cannot change the address of a constant pointer

*p3 = 50;  // ❌ Error: Cannot modify value through a pointer to const
p3 = &b;   // ❌ Error: Cannot change the address of a constant pointer
*/

//////////////////////////////// Dynamic Memory & new/delete////////////////////////////////
/*
void func() {
    int *p = new int(10);  // Allocate memory for an integer and assign 10 to it
    //new int(10) allocates memory for a single integer (typically 4 bytes). //note 10 is not a size 
    //The allocated memory is then initialized with the value 10.
    //p stores the address of this allocated memory.

    int *q = new int(20);  // Allocate memory for another integer and assign 20 to it

    p = q;  // ❌ Memory Leak! The original memory allocated for `p` (holding 10) is lost
            // Now, `p` points to the same memory as `q`, forgetting the first allocation.

    delete p;  // ✅ This deletes the memory `p` (which is now `q`), but...
               // ❌ The memory allocated for `p` at the beginning (10) is never freed

} // ❌ Memory leak: The first allocated memory (holding 10) was lost and never deleted
*/

//////////////////////////////// Smart Pointers (unique_ptr, shared_ptr, weak_ptr)////////////////////////////////
/*
class Test {
public:
    Test() { cout << "Constructor\n"; }
    ~Test() { cout << "Destructor\n"; }
};

int main() {
    Test *t = new Test();  //here *t is a raw pointer 
    unique_ptr<Test> p1(t);  // ❌ BAD PRACTICE: Manually allocating memory with new

    // Reason:
    // - If an exception occurs before 'p1' is assigned, memory leak happens.
    // - Using raw pointers with unique_ptr is unsafe.
    
    // ❌ ERROR: Copying a unique_ptr is not allowed
    // unique_ptr<Test> p2 = p1; // ❌ Compilation error: Copy constructor is deleted

    // ✅ Corrected Code:
    unique_ptr<Test> p1_fixed = make_unique<Test>();  // ✅ Best practice
    unique_ptr<Test> p2_fixed = move(p1_fixed);  // ✅ Ownership transferred

    if (!p1_fixed) cout << "p1_fixed is now nullptr\n";  // p1_fixed no longer owns the object
}
*/

//////////////////////////////// VTable & Virtual Functions with Pointers////////////////////////////////
/*
class Base {
public:
    Base() { cout << "Base Constructor\n"; }
    //~Base() { cout << "Base Destructor\n"; }
    // Destructor in the base class must be virtual
    virtual ~Base() { cout << "Base Destructor\n"; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived Constructor\n"; }
    ~Derived() { cout << "Derived Destructor\n"; }
};

int main() {
  // Creating a Base class pointer and assigning it to a Derived class object
    Base* b = new Derived();
    //delete b;  // What happens?
    // When deleting the base class pointer, the derived class destructor should be called first,
    // then the base class destructor will be called. This happens only if the base class destructor is virtual.
    delete b;  // Now both Base and Derived destructors will be called correctly

    
}*/

////////////////////////////////Implement malloc & free in C++////////////////////////////////
/*
malloc(size): Allocates a block of memory of the requested size and returns a pointer to the beginning of the block.
free(ptr): Frees the memory previously allocated by malloc(). It marks the memory as available again for future allocation.

#include <unistd.h> // For sbrk()

// Custom malloc using sbrk()
void* my_malloc(size_t size) {
//Standard memory allocation functions like malloc(), calloc(), and realloc() use size_t for their size arguments.
    void *ptr = sbrk(size); // Increase the data segment by 'size' bytes
    if (ptr == (void*)-1) {
        // Error handling if sbrk fails
        cerr << "Memory allocation failed" << endl;
        return nullptr;
    }
    return ptr;
}

// Custom free (no-op in this basic example)
void my_free(void* ptr) {
    // For simplicity, we're not actually freeing memory in this basic example.
    // In a full implementation, we'd track allocated blocks and return them to the system.
    // For now, we just print a message.
    cout << "Freeing memory is not implemented in this simple version!" << endl;
}

int main() {
    // Example of using the custom memory manager
    //On a 32-bit system, size_t is typically 32 bits (unsigned int)
    //On a 64-bit system, size_t is typically 64 bits (unsigned long or unsigned long long)
    size_t size = 100; // Requesting 100 bytes of memory

    void* p = my_malloc(size);
    if (p) {
        cout << "Memory allocated at: " << p << endl;
    }

    // Freeing memory (no-op in this basic example)
    my_free(p);

    return 0;
}
*/
return 0;
}
