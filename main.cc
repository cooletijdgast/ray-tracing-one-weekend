#include "rtweekend.h"

#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"

color ray_color(const Ray& ray, const hittable& hittableObject) {
  hit_record recordedHit;
  // Sets color of sphere if it got hit
  if(hittableObject.hit(ray, Interval(0, infinity), recordedHit)) {
    return 0.5 * (recordedHit.normal + rgb_to_byte(color(255, 255, 255)));
  }

  Vector3D unit_direction = unit_vector(ray.direction());
  auto a = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - a) * rgb_to_byte(color(0, 0, 0)) + a * rgb_to_byte(color(178, 130, 180));
}

int main() {
  // Image

  auto aspect_ratio = 16.0 / 9.0;
  int image_width = 400;

  // Calculate height based on width and desired aspect ratio
  int image_height = int(image_width / aspect_ratio);
  image_height = (image_height < 1) ? 1 : image_height;

  // World

  hittable_list hittableObjects;


  // Sphere:
  hittableObjects.add(make_shared<sphere>(Point3D(0, 0, -1), 0.7));

  //	Ground:
  hittableObjects.add(make_shared<sphere>(Point3D(0, -100.5, -1), 100));

  // Camera

  auto focal_length = 1.0;
  auto viewport_height = 2.0;
  auto viewport_width = viewport_height * (double(image_width) / image_height);
  auto camera_center = Point3D(0, 0, 0);

  /*	_____________
      |Vu ->		  |
  Vv  |			      |
    |	|			      |
    v	|___________|
   */

  // Calculate the vectors accross the horizontal and down the vertical viewport edges
  auto viewport_u = Vector3D(viewport_width, 0, 0);
  auto viewport_v = Vector3D(0, -viewport_height, 0);

  // Calculate the horizontal and vertical delta vectors from pixel to pixel
  auto pixel_delta_u = viewport_u / image_width;
  auto pixel_delta_v = viewport_v / image_height;

  // Calculate the location of the upper left pixel
  auto viewport_upper_left =
  camera_center - Vector3D(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
  auto pixel_00_location = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

  // Render

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for(int j = 0; j < image_height; j++) {
    std::clog << "\rScanlines remaing " << (image_height - j) << ' ' << std::flush << "\n";
    for(int i = 0; i < image_width; i++) {
      auto pixel_center = pixel_00_location + (i * pixel_delta_u) + (j * pixel_delta_v);
      auto ray_direction = pixel_center - camera_center;
      Ray ray(camera_center, ray_direction);

      color pixel_color = ray_color(ray, hittableObjects);
      write_color(std::cout, pixel_color);
    }
  }
  std::clog << "\ray Done \n";
}
