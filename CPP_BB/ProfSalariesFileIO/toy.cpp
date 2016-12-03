//Testing out serialization

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Student {
public:
    char FullName[40];
    char CompleteAddress[120];
    char Gender;
    double Age;
    bool SingleParent;
    
};

int main() {
    /*
    Student one;
    
    strcpy(one.FullName, "Cool Man Dude");
    
    strcpy(one.CompleteAddress, "123 Street");
    
    one.Gender = 'M';
    
    one.Age = 16.5;
    
    one.SingleParent = false;
    
    ofstream ofs("something.ros", ios::binary); //makes a binary file
    
    ofs.write((char *)&one, sizeof(one)); //writing to a file!
    
    ofs.close();
    */

    Student two;
    
    ifstream ifs("something.ros", ios::binary);
    
    ifs.read((char *)&two, sizeof(two)); //this is the magic. This is where object "two" gets its member variables
    //istream::read() requires a character pointer array and the streamsize, which is the sizeof(object), which is the same size we put into the file. So it all works out!
    
    
    cout << "Student Information\n";

	cout << "Student Name: " << two.FullName << endl;

	cout << "Address:      " << two.CompleteAddress << endl;
    
    cout << "Age:          " << two.Age << endl;
    
    ifs.close();
    return 0;
}
    