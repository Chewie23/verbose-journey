#include <iostream>

using namespace std;

class Student {
public:
    int number;
    Student() : number(0) {} //AGAIN. This is a default constructor if object is called WITHOUT arguments!!!!
    Student(int number) : number(number) {}
};


class Prof {
public:
    string name, subject;
    int difficulty, num_students;
    
    Prof() : Prof("John Doe", "Comp Sci", 100, 0) {} //Default constructor!! Sort of!
    Prof(const string& name, const string& subject, int difficulty, int num_students)
        : name(name), subject(subject), difficulty(difficulty), num_students(num_students) {}
    
    //Recommended to keep the overloading operator "+" inside the class, to encapsulate it!
    Prof operator+(const Student& students) { //overloading the "+" operator to see what it returns
        return Prof(name, subject, difficulty, num_students + students.number);
        //It returns the SAME object, but with modified student member values!!!
        
    //For OUTSIDE the class we can do...
    //Prof operator+(const Prof& p, const Student& students) {
    //  Prof cool_dude (p.name, p.subject, p.difficulty, p.num_students + students.number);
    //  return dude;
    //}

    }
};

//The below code SHOULD not be "void". Will make "endl;" in the main will be BADDDDDDDD
//as if you did "void << endl;" which makes no sense
ostream& operator<<(ostream& os, const Prof& p) { //overloads the "<<" to print out this format
//"Prof& p" refers to the object you are printing!!
//The order of the parameter names in the function MATTERS!!!!
    os << p.name << " teaches " << p.subject << " and has " << p.num_students << " students";
    //Remember "os" = output stream, thus "cout" in main
    return os; 
    //This function stuff here will make "cout" this format!
}

int main() {
    Prof cool;
    cout << cool << endl;
    cout << cool + Student(30) << endl;
    cout << cool + Student(10) << endl; // Will be only 10! Since we return a COPY of the original object
    //If we want to modify the thing, we should have overloaded "+="
}
