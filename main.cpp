#include <iostream>
#include "triangle.h"

using namespace std;

int main()
{
    Point A,B,C;

    cout<<"Enter triangle coordinates\n";

    cout<<"A: ";
    cin>>A.x>>A.y;

    cout<<"B: ";
    cin>>B.x>>B.y;

    cout<<"C: ";
    cin>>C.x>>C.y;

    if(isDegenerate(A,B,C))
    {
        cout<<"Triangle is degenerate\n";
        return 0;
    }

    cout<<"Area (Heron): "<<areaHeron(A,B,C)<<endl;
    cout<<"Area (Gauss): "<<areaGauss(A,B,C)<<endl;

    int n;

    cout<<"Enter number of points: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        Point P;

        cout<<"Point "<<i+1<<": ";
        cin>>P.x>>P.y;

        int r = pointInTriangle(A,B,C,P);

        if(r==1)
            cout<<"Point inside triangle\n";

        else if(r==2)
            cout<<"Point on border\n";

        else
            cout<<"Point outside triangle\n";
    }

    return 0;
}