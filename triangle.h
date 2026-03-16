#ifndef TRIANGLE_H
#define TRIANGLE_H

struct Point
{
    double x;
    double y;
};

double distance(Point a, Point b);

double areaHeron(Point a, Point b, Point c);
double areaGauss(Point a, Point b, Point c);

double cross(Point a, Point b, Point c);

bool isDegenerate(Point a, Point b, Point c);

int pointInTriangle(Point a, Point b, Point c, Point p);

#endif