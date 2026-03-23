#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>

struct Point {
    double x, y;
};


double distance(const Point& p1, const Point& p2);

struct Triangle {
    Point A, B, C;

    double shoelaceArea() const;  
    double area() const;           
    bool onBorder(const Point& P) const;
    bool contains(const Point& P) const;
    bool containsHeron(const Point& P) const;
};


double heronArea(const Triangle& t);
bool Vyrodzhenyi(const Triangle& t);

#endif
