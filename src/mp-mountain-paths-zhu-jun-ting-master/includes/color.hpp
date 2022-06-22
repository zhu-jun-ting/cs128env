#ifndef COLOR_H
#define COLOR_H

class Color {
public:
  Color() = default;
  Color(int r, int g, int b);
  int Red() const { return red_; }
  int Green() const { return green_; }
  int Blue() const { return blue_; };

private:
  int red_ = 0;
  int green_ = 0;
  int blue_ = 0;
  static const int kMax = 255;
  bool IsValid(int c) const;
};

bool operator==(const Color& rhs, const Color& lhs);

#endif