#ifndef INTERVAL_H
#define INTERVAL_H

class Interval {
  public:
  double min, max;

  Interval() : min(+infinity), max(-infinity) {
  } // default interval is empty

  Interval(double min, double max) : min(min), max(max) {
  }

  double size() const {
    return max - min;
  }

  bool contains(double coordinate) const {
    return min <= coordinate && coordinate <= max;
  }

  bool surrounds(double coordinate) const {
    return min < coordinate && coordinate < max;
  }

  static const Interval empty, universe;
};

const Interval Interval::empty = Interval(+infinity, -infinity);
const Interval Interval::universe = Interval(-infinity, +infinity);

#endif