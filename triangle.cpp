#include "Triangle.h"

// Відстань між точками
double distance(const Point& p1, const Point& p2) {
    return std::sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

// Площа через шнурування
double Triangle::shoelaceArea() const {
    return std::abs(A.x*(B.y - C.y) + B.x*(C.y - A.y) + C.x*(A.y - B.y)) / 2.0;
}

// Площа через Герона
double Triangle::area() const {
    double a = distance(A, B);
    double b = distance(B, C);
    double c = distance(C, A);
    double s = (a + b + c) / 2.0;
    return std::sqrt(s*(s - a)*(s - b)*(s - c));
}

double heronArea(const Triangle& t) {
    return t.area();
}

// Вироджений трикутник
bool Vyrodzhenyi(const Triangle& t) {
    return t.shoelaceArea() < 1e-8;
}

// Точка на кордоні
bool Triangle::onBorder(const Point& P) const {
    double A1 = std::abs((A.x - P.x)*(B.y - P.y) - (B.x - P.x)*(A.y - P.y));
    double A2 = std::abs((B.x - P.x)*(C.y - P.y) - (C.x - P.x)*(B.y - P.y));
    double A3 = std::abs((C.x - P.x)*(A.y - P.y) - (A.x - P.x)*(C.y - P.y));
    return (A1 + A2 + A3 < 1e-8) && ((A1 < 1e-8) || (A2 < 1e-8) || (A3 < 1e-8));
}

// Перевірка через шнурування (всередині трикутника)
bool Triangle::contains(const Point& P) const {
    double total = shoelaceArea();
    double area1 = Triangle{P, B, C}.shoelaceArea();
    double area2 = Triangle{A, P, C}.shoelaceArea();
    double area3 = Triangle{A, B, P}.shoelaceArea();
    return !onBorder(P) && std::abs(total - (area1 + area2 + area3)) < 1e-8;
}

// Перевірка через Герона
bool Triangle::containsHeron(const Point& P) const {
    double total = area();
    double area1 = Triangle{P, B, C}.area();
    double area2 = Triangle{A, P, C}.area();
    double area3 = Triangle{A, B, P}.area();
    return !onBorder(P) && std::abs(total - (area1 + area2 + area3)) < 1e-8;
}