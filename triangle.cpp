#include "triangle.h"
#include <cmath>


double distance(Point a, Point b)
{
    return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}


double areaHeron(Point a, Point b, Point c)
{
    double ab = distance(a,b);
    double bc = distance(b,c);
    double ca = distance(c,a);

    double p = (ab+bc+ca)/2;

    return sqrt(p*(p-ab)*(p-bc)*(p-ca));
}


double areaGauss(Point a, Point b, Point c)
{
    return fabs(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))/2;
}


double cross(Point a, Point b, Point c)
{
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}


bool isDegenerate(Point a, Point b, Point c)
{
    return areaGauss(a,b,c)==0;
}



int pointInTriangle(Point a, Point b, Point c, Point p)
{
    double c1 = cross(a,b,p);
    double c2 = cross(b,c,p);
    double c3 = cross(c,a,p);

    if(c1==0 || c2==0 || c3==0)
        return 2;

    if((c1>0 && c2>0 && c3>0) ||
       (c1<0 && c2<0 && c3<0))
        return 1;

    return 0;
}