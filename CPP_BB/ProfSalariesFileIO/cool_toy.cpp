#include <algorithm>  // Useful for std::sort
#include <iostream>
#include <fstream>
#include <vector>

#include "Professor.h"

using namespace std;

int main() {
    Professor One;
    Professor Two("zbba", "Title", 13, 13);
    Professor Three;
    vector<Professor> generic;
    string line;
    
    cout << Two << endl;

    ofstream ofs("cool.ros", ios::binary);
    Two.serialize(ofs);
    ofs.close();
    /*
    //One = Two;
    //cout << One;
    
    if (One < Two){
       cout << One; 
    }
    else {
        cout << Two;
    }
    */
    
    ifstream ifs("test.txt"); //This guy will grab the info. BINARY IS NOT THE SAME AS TXT SO BE CAREFUL WITH THAT
    
    while (true) {
        Three.deserialize(ifs);
        generic.push_back(Three);
        if(ifs.eof()) {
            break;
        };
    };
    ifs.close();
    /*
    ifs.open("prof_vec_text.txt");
    while (getline(ifs, line)) {
        generic.push_back(line);
    }
    */
    sort(generic.begin(), generic.end());
    for (int i = 0; i < generic.size(); ++i) {
        cout << generic[i] << endl;
    }
    
    return 0;
}