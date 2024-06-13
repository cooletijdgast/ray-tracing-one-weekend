#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray{
	public:
		ray(){}

		ray(const point3& origin, const vector3Points& direction) : orig(origin), dir(direction) {}

		const point3& origin() const { return orig; }
		const vector3Points& direction() const { return dir; }

		point3 at(double t) const {
			return orig + t * dir;
		}

	private:
	       point3 orig;
       	       vector3Points dir;
	};
#endif
