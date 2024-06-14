#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class Vector3D {
  public:
  double component[3];

  Vector3D() : component{ 0, 0, 0 } {
  }
  Vector3D(double comp0, double comp1, double comp2)
  : component{ comp0, comp1, comp2 } {
  }

  double x() const {
    return component[0];
  }
  double y() const {
    return component[1];
  }
  double z() const {
    return component[2];
  }

  Vector3D operator-() const {
    return Vector3D(-component[0], -component[1], -component[2]);
  }
  double operator[](int i) const {
    return component[i];
  }
  double& operator[](int i) {
    return component[i];
  }

  Vector3D& operator+=(const Vector3D& vector) {
    component[0] += vector.component[0];
    component[1] += vector.component[1];
    component[2] += vector.component[2];
    return *this;
  }

  Vector3D& operator*=(double multiplier) {
    component[0] *= multiplier;
    component[1] *= multiplier;
    component[2] *= multiplier;
    return *this;
  }

  Vector3D& operator/=(double divider) {
    return *this *= 1 / divider;
  }

  double length() const {
    return sqrt(length_squared());
  }

  double length_squared() const {
    return component[0] * component[0] + component[1] * component[1] +
    component[2] * component[2];
  }
};

// Point3D is just an alias for vec3, but useful for geometric clarity in the
// code.
using Point3D = Vector3D;

// Vector Utility Functions

inline std::ostream& operator<<(std::ostream& out, const Vector3D& vertical) {
  return out << vertical.component[0] << ' ' << vertical.component[1] << ' '
             << vertical.component[2];
}

inline Vector3D operator+(const Vector3D& horizontal, const Vector3D& vertical) {
  return Vector3D(horizontal.component[0] + vertical.component[0],
  horizontal.component[1] + vertical.component[1],
  horizontal.component[2] + vertical.component[2]);
}

inline Vector3D operator-(const Vector3D& horizontal, const Vector3D& vertical) {
  return Vector3D(horizontal.component[0] - vertical.component[0],
  horizontal.component[1] - vertical.component[1],
  horizontal.component[2] - vertical.component[2]);
}

inline Vector3D operator*(const Vector3D& horizontal, const Vector3D& vertical) {
  return Vector3D(horizontal.component[0] * vertical.component[0],
  horizontal.component[1] * vertical.component[1],
  horizontal.component[2] * vertical.component[2]);
}

inline Vector3D operator*(double multiplier, const Vector3D& vertical) {
  return Vector3D(multiplier * vertical.component[0],
  multiplier * vertical.component[1], multiplier * vertical.component[2]);
}

inline Vector3D operator*(const Vector3D& vertical, double multiplier) {
  return multiplier * vertical;
}

inline Vector3D operator/(const Vector3D& vertical, double divider) {
  return (1 / divider) * vertical;
}

inline double multiplyComponents(const Vector3D& horizontal, const Vector3D& vertical) {
  return horizontal.component[0] * vertical.component[0] +
  horizontal.component[1] * vertical.component[1] +
  horizontal.component[2] * vertical.component[2];
}

inline Vector3D cross(const Vector3D& horizontal, const Vector3D& vertical) {
  return Vector3D(horizontal.component[1] * vertical.component[2] -
  horizontal.component[2] * vertical.component[1],
  horizontal.component[2] * vertical.component[0] -
  horizontal.component[0] * vertical.component[2],
  horizontal.component[0] * vertical.component[1] -
  horizontal.component[1] * vertical.component[0]);
}

inline Vector3D unit_vector(const Vector3D& vertical) {
  return vertical / vertical.length();
}

#endif
