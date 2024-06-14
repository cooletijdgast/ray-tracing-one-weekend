#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

using color = Vector3D;

void write_color(std::ostream& out, const color& pixel_color) {
  auto r = pixel_color.x();
  auto g = pixel_color.y();
  auto b = pixel_color.z();

  // Translate the [0,1] component values to the byte range [0,255]
  int rbyte = int(255.999 * r);
  int gbyte = int(255.999 * g);
  int bbyte = int(255.999 * b);

  // Write out the pixel color components
  out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

double roundToDecimal(double value, int decimalPlaces) {
  double scale = std::pow(10.0, decimalPlaces);
  return std::round(value * scale) / scale;
}

color rgb_to_byte(const color& rgb) {
  color byte_color(0, 0, 0);
  byte_color.component[0] = roundToDecimal((rgb.component[0] / 255.999), 1);
  byte_color.component[1] = roundToDecimal((rgb.component[1] / 255.999), 1);
  byte_color.component[2] = roundToDecimal((rgb.component[2] / 255.999), 1);
  return byte_color;
}


#endif
