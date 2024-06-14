#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class Ray {
  public:
  Ray() {
  }

  Ray(const Point3D& origin, const Vector3D& direction)
  : orig(origin), dir(direction) {
  }

  const Point3D& origin() const {
    return orig;
  }
  const Vector3D& direction() const {
    return dir;
  }

  Point3D at(double t) const {
    return orig + t * dir;
  }

  private:
  Point3D orig;
  Vector3D dir;
};
#endif
