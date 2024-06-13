#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"

class sphere : public hittable {
public:
  sphere(const point3 &center, double radius): center(center), radius(fmax(0, radius)) {}

  bool hit(const ray &currentRay, interval rayInterval,hit_record &recordedHit) const override {
    vector3Points originToCenter = center - currentRay.origin();
    auto a = currentRay.direction().length_squared();
    auto h = dot(currentRay.direction(), originToCenter);
    auto c = originToCenter.length_squared() - radius * radius;

    auto discriminant = h * h - a * c;
    if (discriminant < 0) {
      return false;
    }

    auto sqrtd = sqrt(discriminant);

    // Find nearest root that lies in the acceptable range
    auto root = (h - sqrtd) / a;
    if (!rayInterval.surrounds(root)) {
      root = (h + sqrtd) / a;
      if (!rayInterval.surrounds(root)) {
        return false;
      }
    }

    recordedHit.t = root;
    recordedHit.p = currentRay.at(recordedHit.t);
    vector3Points outward_normal = (recordedHit.p - center) / radius;
    recordedHit.set_face_normal(currentRay, outward_normal);

    return true;
  }

private:
  point3 center;
  double radius;
};

#endif