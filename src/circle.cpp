// Copyright 2022 UNN-CS
#include <cstdint>
#include <cmath>
#include <stdexcept>
#include "circle.h"

Circle::Circle(double r) : radius(0.0), ference(0.0), area(0.0) {
    setRadius(r);
}

void Circle::setRadius(double r) {
    if (r < 0) {
        throw std::invalid_argument("Incorrect radius");
    }
    radius = r;
    ference = 2 * pi * r;
    area = pi * r * r;
}
void Circle::setFerence(double f) {
    if (f < 0) {
        throw std::invalid_argument("Incorrect ference");
    }
    ference = f;
    radius = f / (2 * pi);
    area = pi * radius * radius;
}
void Circle::setArea(double a) {
    if (a < 0) {
        throw std::invalid_argument("Incorrect area");
    }
    area = a;
    radius = std::sqrt(a / pi);
    ference = 2 * pi * radius;
}
double Circle::getRadius() {
    return radius;
}
double Circle::getFerence() {
    return ference;
}
double Circle::getArea() {
    return area;
}
