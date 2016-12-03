/*
General Idea

Your job is to make some kind of art using recursion. For example, you could draw a tree recursively or a simple fractal (Links to an external site.).

Write a program which uses the HTMLCanvas to output HTML to a file that's passed in as argv[1]. For example, if your program is called "my_program", 
then I should be able to run your program like "./my_program art.html" (on Mac/Linux) or "my_program.exe art.html" (on Windows) 
and be able to open up art.html to see your art. 

**DO NOT modify canvas.h or canvas.cpp.**

The OStreamCanvas class is provided for your convenience. You do not need to use it. If the HTML produced by your art is larger than 256 Kilobytes, you will get 0 points.

When you're done, upload your code (except canvas.h and canvas.cpp) to the Grade Oven HW 04 page (Links to an external site.).
*/

//LIVE EXAMPLE BELOW
#include <iostream>
#include <fstream>

#include "canvas.h"

void draw_recurse(HTMLCanvas& paper, double temp, double x1, double y1, double x2, 
                    double y2, double x4, double y4, double x5, double y5) {
    //WELL. Need to draw 4 lines. How to implment that while loop in recursive form??
    paper.start();
    temp = temp/2;
    
    if (temp >= .0125) {
        double x3, y3, x6, y6;
        paper.draw_line(x1, y1, x2, y2); //makes initial line
        paper.draw_line(x4, y4, x5, y5);
        paper.stop();
      
        x1 = x2; 
        y1 = y2;
        x3 = (x2 - temp);
        y3 = (y2 - temp - .1); //these makes the branches
        x2 = (x2 - temp);
        y2 = (y2 - temp + .1);

        paper.draw_line(x1, y1, x3, y3);
        
        x4 = x5;
        y4 = y5;
        x6 = (x5 + temp);
        y6 = (y5 - temp - .1);
        x5 = (x5 + temp);
        y5 = (y5 - temp + .1);
        paper.draw_line(x4, y4, x6, y6);
        paper.stop();
        
        draw_recurse(paper, temp, x1, y1, x2, y2, x4, y4, x5, y5);  
    }
}
//Below is for testing the recursive drawing in command line
void draw_recurse2(OStreamCanvas& paper, double temp, double x1, double y1, double x2, 
                    double y2, double x4, double y4, double x5, double y5) {
    //WELL. Need to draw 4 lines. How to implment that while loop in recursive form??
    paper.start();
    temp = temp/2;
    
    if (temp >= .0125) {
        double x3, y3, x6, y6;
        paper.draw_line(x1, y1, x2, y2); //makes initial line
        paper.draw_line(x4, y4, x5, y5);
        paper.stop();
      
        x1 = x2; 
        y1 = y2;
        x3 = (x2 - temp);
        y3 = (y2 - temp - .1); //these makes the branches
        x2 = (x2 - temp);
        y2 = (y2 - temp + .1);

        paper.draw_line(x1, y1, x3, y3);
        
        x4 = x5;
        y4 = y5;
        x6 = (x5 + temp);
        y6 = (y5 - temp - .1);
        x5 = (x5 + temp);
        y5 = (y5 - temp + .1);
        paper.draw_line(x4, y4, x6, y6);
        paper.stop();
        
        draw_recurse2(paper, temp, x1, y1, x2, y2, x4, y4, x5, y5);  
    }
}

int main (int argc, const char* argv[]) {
    std::ofstream fancy_canvas, cool;
    if (argc > 1) {
       fancy_canvas.open(argv[1]); 
    }
    else {
       fancy_canvas.open("art.html");  
    }
    
    
    HTMLCanvas canvas(fancy_canvas, 100);
    

    double temp = 0.4;  
    double x1, y1, x2, y2, x4, y4, x5, y5;

    x1 = .5;
    y1 = 1;
    x2 = 0.5;
    y2 = 0.6;
    x4 = x1;
    y4 = y1;
    x5 = x2;
    y5 = y2;


    draw_recurse(canvas, temp, x1, y1, x2, y2, x4, y4, x5, y5);
    fancy_canvas.close();
    return 0;
}
      //BELOW IS PROTOTYPE CODE!!! 

       //OStreamCanvas stone(std::cout, 100); 
    //draw_recurse2(stone, temp, x1, y1, x2, y2, x4, y4, x5, y5); //works! Now to put in HTML
   /*
  //YAYYY. Works
  while (temp >= .025) {
      //This, realize, is only the LEFT branches of the LEFT HALF
      temp = temp/2;
      draw_recurse(canvas, x1, y1, x2, y2);
      x1 = x2; 
      y1 = y2;
      x3 = (x2 - temp);
      y3 = (y2 - temp - .1);
      x2 = (x2 - temp);
      y2 = (y2 - temp + .1);
      
      //HOPEFULLY THIS DRAWS THE RIGHT BRANCH ON THE LEFT HALF
      draw_recurse(canvas, x1, y1, x3, y3); //It does, but kind of funky looking
      
      //Now for the right half
      //Right branches of right half
      draw_recurse(canvas, x4, y4, x5, y5);
      x4 = x5;
      y4 = y5;
      x6 = (x5 + temp);
      y6 = (y5 - temp - .1);
      x5 = (x5 + temp);
      y5 = (y5 - temp + .1);
      //Left branches of right half
      draw_recurse(canvas, x4, y4, x6, y6);
  }
  
  //BELOW IS A BARREN TREE. MAKE THE SAME DRAWING WITH RECURSION.
  //MAKE IT MORE LOGICAL AND PATTERN-Y
  std::cout << "--------------------------------------------" <<std::endl;
  draw_recurse(canvas, 0.5, 1, 0.5, 0.6); //good starting point
  std::cout << "--------------------------------------------" <<std::endl;
  draw_recurse(canvas, .5, .6, .3, .4); //the left first fork
  draw_recurse(canvas, .5, .6, .7, .4); //the right first fork
  std::cout << "--------------------------------------------" <<std::endl;
  //left side
  draw_recurse(canvas, .3, .4, .2, .5); //the left 2nd fork, of left fork
  draw_recurse(canvas, .3, .4, .2, .3); //the right 2nd fork, of left fork
  std::cout << "--------------------------------------------" <<std::endl;
  //right side
  draw_recurse(canvas, .7, .4, .8, .5); //the left 2nd fork, of right fork note the first coordinate pair
  draw_recurse(canvas, .7, .4, .8, .3); //the right 2nd fork, of right fork
  std::cout << "--------------------------------------------" <<std::endl;
  
  //left side
  draw_recurse(canvas, .2, .5, .1, .6); //the left 3rd fork,
  draw_recurse(canvas, .2, .5, .1, .4); //the right 3rd fork
  
  std::cout << "--------------------------------------------" <<std::endl;
  draw_recurse(canvas, .2, .3, .3, .2); //the left 3rd fork, of right fork note the first coordinate pair
  draw_recurse(canvas, .2, .3, .1, .2); //the right 3rd fork, of right fork
  
  std::cout << "--------------------------------------------" <<std::endl;
  
  //right side
  draw_recurse(canvas, .8, .4, .9, .3); //the left 3rd fork, of right fork note the first coordinate pair
  draw_recurse(canvas, .8, .4, .9, .5); //the right 3rd fork, of right fork
  
  std::cout << "--------------------------------------------" <<std::endl;
  draw_recurse(canvas, .7, .2, .8, .15); //the right 3rd fork, of right fork note the first coordinate pair
  draw_recurse(canvas, .7, .2, .6, .15); //the left 3rd fork, of right fork
  */


/*
//Will check for cmd line arguments! Need to use 
//HTMLCanvas(std::ostream& os, int screen_side_len), NOT std::cout!!!!
int main (int argc, const char* argv[]) {
    const char* fancy_canvas =
    argc > 1 ? argv[1] : "art.html"; //takes from command line
    std::ifstream art_drawing(fancy_canvas); //makes input file, with name based off of command line/default
    if (!art_drawing.good()) {//checks if bits are "good" If not, then error message below
        std::cout << "Could not open file \"" << fancy_canvas << "\"" << std::endl;
        std::cout << "Goodbye" << std::endl;
        exit(0);
    }
}



*/