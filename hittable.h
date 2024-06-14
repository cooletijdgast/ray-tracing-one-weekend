#ifndef HITTABLE_H
#define HITTABLE_H

#include "rtweekend.h"

class hit_record {
  public:
  Point3D p;
  Vector3D normal;
  double t;
  bool front_face;

  void set_face_normal(const Ray& ray, const Vector3D& outward_normal) {
    // Sets the hit record normal vector
    // NOTE: the parameter `outward_normal` is assumed to have unit_length

    front_face = multiplyComponents(ray.direction(), outward_normal) < 0;
    normal = front_face ? outward_normal : -outward_normal;
  }
};

class hittable {
  public:
  virtual ~hittable() = default;

  virtual bool hit(const Ray& ray, Interval ray_t, hit_record& rec) const = 0;
};

#endif