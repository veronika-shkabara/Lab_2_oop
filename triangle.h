#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>

struct Point {
    double x, y;
};

// Відстань між точками
double distance(const Point& p1, const Point& p2);

struct Triangle {
    Point A, B, C;

    double shoelaceArea() const;  // площа по шнуруванню
    double area() const;           // площа по Герону

    bool onBorder(const Point& P) const;
    bool contains(const Point& P) const;
    bool containsHeron(const Point& P) const;
};

// Функції для роботи з трикутником
double heronArea(const Triangle& t);
bool Vyrodzhenyi(const Triangle& t);

#endif