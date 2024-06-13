#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vector3Points {
   public:
    double component[3];

    vector3Points() : component{0, 0, 0} {}
    vector3Points(double comp0, double comp1, double comp2) : component{comp0, comp1, comp2} {}

    double x() const { return component[0]; }
    double y() const { return component[1]; }
    double z() const { return component[2]; }

    vector3Points operator-() const {
        return vector3Points(-component[0], -component[1], -component[2]);
    }
    double  operator[](int i) const { return component[i]; }
    double& operator[](int i) { return component[i]; }

    vector3Points& operator+=(const vector3Points& vector) {
        component[0] += vector.component[0];
        component[1] += vector.component[1];
        component[2] += vector.component[2];
        return *this;
    }

    vector3Points& operator*=(double multiplier) {
        component[0] *= multiplier;
        component[1] *= multiplier;
        component[2] *= multiplier;
        return *this;
    }

    vector3Points& operator/=(double divider) { return *this *= 1 / divider; }

    double length() const { return sqrt(length_squared()); }

    double length_squared() const {
        return component[0] * component[0] + component[1] * component[1] +
               component[2] * component[2];
    }
};

// point3 is just an alias for vec3, but useful for geometric clarity in the code.
using point3 = vector3Points;

// Vector Utility Functions

inline std::ostream& operator<<(std::ostream& out, const vector3Points& vertical) {
    return out << vertical.component[0] << ' ' << vertical.component[1] << ' '
               << vertical.component[2];
}

inline vector3Points operator+(const vector3Points& horizontal, const vector3Points& vertical) {
    return vector3Points(horizontal.component[0] + vertical.component[0],
                         horizontal.component[1] + vertical.component[1],
                         horizontal.component[2] + vertical.component[2]);
}

inline vector3Points operator-(const vector3Points& horizontal, const vector3Points& vertical) {
    return vector3Points(horizontal.component[0] - vertical.component[0],
                         horizontal.component[1] - vertical.component[1],
                         horizontal.component[2] - vertical.component[2]);
}

inline vector3Points operator*(const vector3Points& horizontal, const vector3Points& vertical) {
    return vector3Points(horizontal.component[0] * vertical.component[0],
                         horizontal.component[1] * vertical.component[1],
                         horizontal.component[2] * vertical.component[2]);
}

inline vector3Points operator*(double multiplier, const vector3Points& vertical) {
    return vector3Points(multiplier * vertical.component[0], multiplier * vertical.component[1],
                         multiplier * vertical.component[2]);
}

inline vector3Points operator*(const vector3Points& vertical, double multiplier) {
    return multiplier * vertical;
}

inline vector3Points operator/(const vector3Points& vertical, double divider) {
    return (1 / divider) * vertical;
}

inline double dot(const vector3Points& horizontal, const vector3Points& vertical) {
    return horizontal.component[0] * vertical.component[0] +
           horizontal.component[1] * vertical.component[1] +
           horizontal.component[2] * vertical.component[2];
}

inline vector3Points cross(const vector3Points& horizontal, const vector3Points& vertical) {
    return vector3Points(horizontal.component[1] * vertical.component[2] -
                             horizontal.component[2] * vertical.component[1],
                         horizontal.component[2] * vertical.component[0] -
                             horizontal.component[0] * vertical.component[2],
                         horizontal.component[0] * vertical.component[1] -
                             horizontal.component[1] * vertical.component[0]);
}

inline vector3Points unit_vector(const vector3Points& vertical) {
    return vertical / vertical.length();
}

#endif
