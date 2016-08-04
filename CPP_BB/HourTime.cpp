#include <iostream>

double convertToHour(int hour, int min) {
    //Converts minutes into hours and combines them with hour amount
    double timeInHour, decHour;
    double minInHour;
    if(min > 60){
        minInHour = (int)min / 60;
        min = min - (minInHour * 60);
    }
    else{
        minInHour = 0;
    }
    decHour = (double)min / 60;
    timeInHour = hour + decHour + minInHour;
    
    return timeInHour;
}

int main() {
    int hour, min;
    
    hour = 12;
    min = 96;
    
    std::cout << convertToHour(hour, min) << std::endl;
    return 0;
}