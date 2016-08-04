#pragma once

#include <iostream>
#include <string>

class AbstractCanvas {
public:
  virtual ~AbstractCanvas() = default;
  // start() must be called before drawing any lines
  virtual void start() = 0;
  // stop() must be called after drawing all lines
  virtual void stop() = 0;
  // Buffer a line within a box where (0, 0) is the top-left corner and (1, 1)
  // is the bottom-right corner.
  virtual void draw_line(double x1, double y1, double x2, double y2) = 0;
};

class OStreamCanvas : public AbstractCanvas {
protected:
  std::ostream& output_;
  const int screen_width_, screen_height_;
  // The text screen is a 1-dimensional array that is treated like a
  // 2-dimensional array with screen_width_ + 1 columns and screen_height_
  // rows.
  std::string screen_;
public:
  OStreamCanvas(std::ostream& os=std::cout, int screen_width=80);
  ~OStreamCanvas() = default;
  void start() override;
  void stop() override;
  void draw_line(double x1, double y1, double x2, double y2) override;
};

class HTMLCanvas : public AbstractCanvas {
protected:
  std::ostream& output_;
  const int screen_side_len_;
public:
  HTMLCanvas(std::ostream& os=std::cout, int screen_side_len=480);
  ~HTMLCanvas() = default;
  void start() override;
  void stop() override;
  void draw_line(double x1, double y1, double x2, double y2) override;
};