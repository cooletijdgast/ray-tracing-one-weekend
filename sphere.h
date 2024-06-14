#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"

class sphere : public hittable {
  public:
  sphere(const Point3D& center, double radius)
  : center(center), radius(fmax(0, radius)) {
  }

  bool hit(const Ray& ray, Interval rayInterval, hit_record& recordedHit) const override {
    Vector3D originToCenter = center - ray.origin();
    auto rayDirectionSqrt = ray.direction().length_squared();
    auto h = multiplyComponents(ray.direction(), originToCenter);
    auto c = originToCenter.length_squared() - radius * radius;

    auto discriminant = h * h - rayDirectionSqrt * c;
    if(discriminant < 0) {
      return false;
    }

    auto sqrtd = sqrt(discriminant);

    // Find nearest root that lies in the acceptable range
    auto root = (h - sqrtd) / rayDirectionSqrt;
    if(!rayInterval.surrounds(root)) {
      root = (h + sqrtd) / rayDirectionSqrt;
      if(!rayInterval.surrounds(root)) {
        return false;
      }
    }

    recordedHit.t = root;
    recordedHit.p = ray.at(recordedHit.t);
    Vector3D outward_normal = (recordedHit.p - center) / radius;
    recordedHit.set_face_normal(ray, outward_normal);

    return true;
  }

  private:
  Point3D center;
  double radius;
};

#endif