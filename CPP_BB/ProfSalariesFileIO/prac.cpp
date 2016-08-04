#include <fstream>
#include <iostream>

using namespace std;

string deserialize(istream& is) {
    string container;
    is >> container;
    return container;
}

int main() {
    string line;
    ifstream input_file;
    input_file.open("A-G.txt");
    
    line = deserialize(input_file);
    cout << line << endl;
    
    input_file >> line;
    input_file.close();
    cout << line << endl;
}