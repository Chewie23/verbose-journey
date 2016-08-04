#include <algorithm>  // max
#include <cmath>  // abs
#include <cstring>  // memset

#include "canvas.h"

OStreamCanvas::OStreamCanvas(std::ostream& os, int screen_width) //Contructor, that requires parameters to be filled. Overloads default constructor from H file
  : output_(os), screen_width_(screen_width) , screen_height_(screen_width_ / 2),
    screen_(screen_height_ * (screen_width_ + 1), '?') {
  for (int y = 0; y < screen_height_; ++y) {
    // Set this row to be a bunch of ' ', then a '\n' that is just off screen.
    memset(&screen_[y * (screen_width_ + 1)], ' ', screen_width_); //memset is pretty cool. It points to the first parameter's memory block, fills it with ' ' "screen_width_" times!
    //The API: memset[memory_space_ptr, object_to_replace_memory, num_of_times_to_use_object]
    screen_[y * (screen_width_ + 1) + screen_width_] = '\n';
  }
}

void OStreamCanvas::start() { //literally calls for a start of the festivities by doing...NOTHING???
}

void OStreamCanvas::stop() { //Stops and flushes the output
  output_ << screen_;
  output_.flush();
}

void OStreamCanvas::draw_line(double x1, double y1, double x2, double y2) {
  // Convert the floating point coordinates to actual coordinates on the screen
  x1 *= screen_width_;
  y1 *= screen_height_;
  x2 *= screen_width_;
  y2 *= screen_height_;
  // Calculate the maximum of the number of pixels (chars) that need to be drawn
  // vertically or horizontally.  Add a buffer of 1 pixel just in case this
  // would result in a line that's less than one pixel big.
  int max_steps = std::max(std::abs(x1 - x2), std::abs(y1 - y2)) + 1;
  for (int step = 0; step <= max_steps; ++step) {
    double progress = static_cast<double>(step) / max_steps;
    int x = progress * x1 + (1 - progress) * x2;
    int y = progress * y1 + (1 - progress) * y2;
    if (x < 0 || x >= screen_width_ || y < 0 || y >= screen_height_) {
      continue;
    }
    screen_[y * (screen_width_ + 1) + x] = '#';
  }
}




HTMLCanvas::HTMLCanvas(std::ostream& os, int screen_side_len)
  : output_(os), screen_side_len_(screen_side_len) {
}

void HTMLCanvas::start() {
  output_ <<
    "<!doctype html>\n"
    "<html>\n"
    "<body>\n\n"
    "<canvas id=\"HTMLCanvas\" width=\"" << screen_side_len_ <<
    "\" height=\"" << screen_side_len_ << "\" style=\"border:2px solid #000000;\">"
    "Your browser does not support the HTML5 canvas tag."
    "</canvas>\n\n"
    "<script>\n"
    "var c = document.getElementById(\"HTMLCanvas\");\n"
    "var ctx = c.getContext(\"2d\");\n"
    "ctx.lineWidth = 3;\n";
  output_.flush();
}

void HTMLCanvas::stop() {
  output_ <<
    "</script>\n\n"
    "</body>\n"
    "</html>\n";
  output_.flush();
}

void HTMLCanvas::draw_line(double x1, double y1, double x2, double y2) {
  x1 *= screen_side_len_;
  y1 *= screen_side_len_;
  x2 *= screen_side_len_;
  y2 *= screen_side_len_;
  output_ <<
    "ctx.moveTo(" << x1 << ", " << y1 << ");\n"
    "ctx.lineTo(" << x2 << ", " << y2 << ");\n"
    "ctx.stroke();\n";
}