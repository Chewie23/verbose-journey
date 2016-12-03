//main for HW_4
//Remember to run it as g++ std=c++11 Professor.cpp HW_4.cpp -o Prof.exe && ./Prof.exe

//TODO: Factor out repeated code. 
//TODO: Find a way to parameterize "argv[]"

#include <algorithm>  // Useful for std::sort
#include <iostream>
#include <fstream>
#include <vector>

#include "Professor.h"


int main(int argc, const char *argv[]) {
    Professor generic_prof, name_holder1, name_holder2;
    const char* professor_filename =
    argc > 1 ? argv[1] : "2014-foothill-cs-simplified.txt"; //takes from command line
    std::vector<Professor> professors;
    std::ifstream professors_file(professor_filename); //makes input file, with name based off of command line/default
    if (!professors_file.good()) {//checks if bits are "good" If not, then error message below
        std::cout << "Could not open file \"" << professor_filename << "\"" << std::endl;
        std::cout << "Goodbye" << std::endl;
        exit(0);
    }
    
    while (generic_prof.deserialize(professors_file)) { //reads file, four lines at a time, and will only break when it has no more lines!
        professors.push_back(generic_prof);
      };

    professors_file.close();

    sort(professors.begin(), professors.end()); // Code to sort professors by name
    
    //Checks for filter(s)
    if (argc < 3) {
        for (int i = 0; i < professors.size(); ++i) {
            std::cout << professors[i];
        }
    }
    
    else{ 
        for (const Professor& p : professors) { //fancy way to loop over a range/container/vector. In Python would be the same as "for n in array"
            if ((std::string(argv[2]) == "name") && argc <= 5) { 
                name_holder1.name = argv[4];
                if ((std::string(argv[3]) == "less_than")){
                    if ((p < name_holder1)) {
                        p.serialize(std::cout);
                        }
                    }
                else if ((std::string(argv[3]) == "greater_than")) {
                    if ((p > name_holder1)) {
                        p.serialize(std::cout);
                    }   
                }
            }
            
            else if ((std::string(argv[5]) == "name") && argc <= 8) { 
                name_holder1.name = argv[4];
                name_holder2.name = argv[7];
                //Will check the various combination of names and how they interact/divide the list
                if (name_holder2 > name_holder1) {
                    if ((std::string(argv[6]) == "less_than") && (std::string(argv[3]) == "greater_than")){
                        if (p < name_holder2 && p > name_holder1) {
                            p.serialize(std::cout);
                            }
                    }
                        else if ((std::string(argv[6]) == "greater_than") && (std::string(argv[3]) == "less_than")) {
                            if (p > name_holder2 || p < name_holder1) { //Checks letters above 2nd filter and letters below 1st filter
                                p.serialize(std::cout);
                            }
                        }
                        else if ((std::string(argv[6]) == "greater_than") && (std::string(argv[3]) == "greater_than")) {
                            if (p > name_holder2 && p > name_holder1) {
                                p.serialize(std::cout);
                            }
                        }
                        else if ((std::string(argv[6]) == "less_than") && (std::string(argv[3]) == "less_than")) {
                            if (p < name_holder2 && p < name_holder1) {
                                p.serialize(std::cout);
                            }
                        }
                }
                else {
                    if ((std::string(argv[6]) == "less_than") && (std::string(argv[3]) == "greater_than")){
                        if (p < name_holder2 || p > name_holder1) { //Checks letters below 2nd filter and letters above 1st filter
                            p.serialize(std::cout);
                            }
                    }
                    else if ((std::string(argv[6]) == "greater_than") && (std::string(argv[3]) == "less_than")) {
                        if (p > name_holder2 && p < name_holder1) {
                            p.serialize(std::cout);
                        }
                    }
                    else if ((std::string(argv[6]) == "greater_than") && (std::string(argv[3]) == "greater_than")) {
                        if (p > name_holder2 && p > name_holder1) {
                            p.serialize(std::cout);
                        }
                    }
                    else if ((std::string(argv[6]) == "less_than") && (std::string(argv[3]) == "less_than")) {
                        if (p < name_holder2 && p < name_holder1) {
                            p.serialize(std::cout);
                        }
                    }    
                }
            }
        }   
    }
    
    
    return 0;
}