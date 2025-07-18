#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class StudentData {
private:
    // Used for constructor without parameter
    string schoolName;
    string schoolAddress;
    string studentName;
    int studentID;
    char studentGrade;

    // Used for constructor with parameter
    struct Student {
        string sStudentName;
        int sStudentID;
        char sStudentGrade;
        // Student struct's constructor is only used for creating instances of the Student struct
        Student(string name, int id, char grade): sStudentName(name), sStudentID(id), sStudentGrade(grade) {}
    };
    vector<Student> studentsVector; // data structure to hold different students' data

    // Used for constructor with Deep Copy
    char* student_name;

public:
    // Constructor without parameter
    StudentData() : schoolName(""), schoolAddress(""), studentName("Invalid Name"), studentID(0), studentGrade('C'), student_name(nullptr) {
        //its good practice to set default  value
    }
    
    // Constructor with parameter
    StudentData(string schoolName, string schoolAddress) : schoolName(schoolName), schoolAddress(schoolAddress), student_name(nullptr) {}

    // Shallow Copy constructor
    //A shallow copy creates a new object, but it does not allocate new memory for dynamic members like pointers.
    StudentData(const StudentData& other ,bool deepCopy) {
        schoolName = other.schoolName;
        schoolAddress = other.schoolAddress;
        studentsVector = other.studentsVector; //create a copy of student data 
        
         // Perform deep copy for student_name
         //The constructor ensures that student_name has its own separate memory. 
         //If you modify student_name later,
        //it won’t affect other objects, even if they share the same string conten
        if(deepCopy){
            if (other.student_name) {
                student_name = new char[strlen(other.student_name)+1]; 
                strcpy(student_name,other.student_name);
                // allocate new memory for dynamic members like pointers
            } else {
                student_name = nullptr;
            }
        }else{
            student_name = other.student_name;
        }
        // Debugging output for shallow or deep copy
        cout << (deepCopy ? "Deep Copy Constructor Called!" : "Shallow Copy Constructor Called!") << endl;
    }

    // Destructor
    ~StudentData() {
        if(!studentName.empty()){
            cout<< "Calling Destructor for StudentName: " <<studentName<<endl; 
        }
       //Destructors in this case don't need to deal with the students vector explicitly, 
       //vector automatically handles memory cleanup.
       if(!schoolName.empty()){
            cout<< "Calling Destructor for StudentName: " <<schoolName<<endl;
        }
        
        // Cleanup dynamically allocated memory deepcopy
        //delete[] student_name because it is an array of dynamically allocated objects. 
        delete[] student_name;
    }

    // Setter functions
    void SetStudentName(string name) {
        studentName = name;
    }

    void SetStudentID(int id) {
        studentID = id;
    }

    void SetStudentGrade(char grade) {
        if (grade == toupper(grade)) {
            studentGrade = tolower(grade);
        } else {
            studentGrade = toupper(grade);
        }
    }

    // Getter functions
    string GetStudentName() const {
        return studentName;
    }

    int GetStudentID() const {
        return studentID;
    }

    char GetStudentGrade() const {
        return studentGrade;
    }

    string GetSchoolDetails() const {
        return "School Name: New School\nSchool Address: New City, INDIA";
    }

    // Method to add student data
    void AddStudentData(string studentName, int studentID, char studentGrade) {
        //struct , constructor with parameter
        //Student newStduent (studentName ,studentID, toupper(studentGrade));
        //studentsVector.push_back(newStduent);
        //emplace_back() if you want the cleanest and most efficient way to add a new student 
        studentsVector.emplace_back(studentName, studentID, toupper(studentGrade));
    }

    // Method to display student data
    void DisplayStudentsData() {
        cout << "School Name: " << schoolName << endl;
        cout << "School Address: " << schoolAddress << endl;
        cout << "List of Students: " << endl;
        for (auto& student : studentsVector) {
            cout << "Student Name: " << student.sStudentName << endl;
            cout << "Student ID: " << student.sStudentID << endl;
            cout << "Student Grade: " << student.sStudentGrade << endl;
            cout << endl;
        }
        cout << "---------------------------" << endl;
    }

    // Method to reset all student data
    void ResetAllStudentData() {
        for (auto& student : studentsVector) {
            student.sStudentName = "";
            student.sStudentID = 0;
            student.sStudentGrade = '\0'; // Resetting the grade to null character
        }
        cout << "All student data has been reset to zero" << endl;
    }
};

int main() {
    // For constructor without parameter
    StudentData firstStudent;
    // Set student data
    firstStudent.SetStudentName("Rahul LN");
    firstStudent.SetStudentID(10);
    firstStudent.SetStudentGrade('a');
    // Get student data
    cout << "Student Data for Constructor without parameter" << endl;
    cout << "First Student Data" << endl;
    cout << firstStudent.GetSchoolDetails() << endl;
    cout << "Name: " << firstStudent.GetStudentName() << endl;
    cout << "ID: " << firstStudent.GetStudentID() << endl;
    cout << "Grade: " << firstStudent.GetStudentGrade() << endl;
    cout << endl;

    StudentData secondStudent;
    // Set student data
    secondStudent.SetStudentName("Rohan LN");
    secondStudent.SetStudentID(11);
    secondStudent.SetStudentGrade('B');
    // Get student data
    cout << "Second Student Data" << endl;
    cout << secondStudent.GetSchoolDetails() << endl;
    cout << "Name: " << secondStudent.GetStudentName() << endl;
    cout << "ID: " << secondStudent.GetStudentID() << endl;
    cout << "Grade: " << secondStudent.GetStudentGrade() << endl;
    cout << endl;

    // For constructor with parameter
    //Inorder to get rid of creating a object and calling functions again and again lets use the below approach 
    StudentData* student = new StudentData("WorldWide School", "New City, World");
    student->AddStudentData("Mr.A", 12, 'a');
    student->AddStudentData("Mr.B", 13, 'b');
    student->AddStudentData("Mr.C", 14, 'C');
    // Display the student Data for constructor with parameter
    cout << "Student Data for constructor with parameter" << endl;
    student->DisplayStudentsData();

    // Shallow copy constructor  
    StudentData* shallowCopiedData = new StudentData(*student ,false); 
    cout << "Student Data for shallow copy constructor " << endl;
    shallowCopiedData->DisplayStudentsData();
    cout << endl;
    
    // Deep copy constructor  
    StudentData* deepCopiedData = new StudentData(*student ,true); 
    cout << "Student Data for deep copy constructor (before modification)" << endl;
    deepCopiedData->DisplayStudentsData();
    cout << endl;
    //Modify the deep copy data 
    deepCopiedData->AddStudentData("New Stduent", 99 ,'A');
    cout << "\nDeep Copied Student Data (after modification):" << endl;
    deepCopiedData->DisplayStudentsData();

    // Reset all data to zero
    student->ResetAllStudentData();
    //deepCopiedData->ResetAllStudentData();//because of new addition
    student->DisplayStudentsData();
    
    // Deallocate this single instance or object
    /*if you don't use delete student; for dynamically allocated memory, it can lead to a memory leak. 
    because its not freed (using delete), 
    and the memory remains reserved by the program without being used, ultimately causing the program 
    to use more memory than necessary, which can lead to 
    1)Slow down the program:performance issues 
    2)Cause system crashes: If the memory usage exceeds available system memory
    3)Exhaust memory: In a long-running program this could eventually exhaust all available memory, 
    resulting in crashes (Aging Test)*/
    
    //Call delete in main() for objects that you allocate 
    //with new (like student, shallowCopiedData, and deepCopiedData).
    delete shallowCopiedData;
    delete deepCopiedData;
    delete student;

    return 0;
}
