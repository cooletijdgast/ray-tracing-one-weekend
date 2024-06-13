#ifndef INTERVAL_H
#define INTERVAL_H

class interval {
public:
  double min, max;

  interval() : min(+infinity), max(-infinity) {} // default interval is empty

  interval(double min, double max) : min(min), max(max) {}

  double size() const { return max - min; }

  bool contains(double coordinate) const {
    return min <= coordinate && coordinate <= max;
  }

  bool surrounds(double coordinate) const {
    return min < coordinate && coordinate < max;
  }

  static const interval empty, universe;
};

const interval interval::empty = interval(+infinity, -infinity);
const interval interval::universe = interval(-infinity, +infinity);

#endif