// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>
const double pi = 3.141592653589793;
class Circle {
 public:
    explicit Circle(double r);
    Circle() : radius(0.0), ference(0.0), area(0.0) {};

    void setRadius(double r);
    void setFerence(double f);
    void setArea(double a);
    double getRadius();
    double getFerence();
    double getArea();
 private:
    double radius;
    double ference;
    double area;
};

#endif  // INCLUDE_CIRCLE_H_
