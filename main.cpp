#include "Triangle.h"
#include <iostream>
using namespace std;

int main() {
    Triangle t;

    cout << "Enter coordinates of vertex A (x y): ";
    cin >> t.A.x >> t.A.y;
    cout << "Enter coordinates of vertex B (x y): ";
    cin >> t.B.x >> t.B.y;
    cout << "Enter coordinates of vertex C (x y): ";
    cin >> t.C.x >> t.C.y;

    if (Vyrodzhenyi(t)) {
        cout << "Warning: Triangle is degenerate!" << endl;
    } else {
        cout << "Area (Heron):      " << heronArea(t) << endl;
        cout << "Area (Shoelace):   " << t.shoelaceArea() << endl;
    }

    int n;
    cout << "How many points to check? ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        Point p;
        cout << "Point " << i << " (x y): ";
        cin >> p.x >> p.y;

        cout << "  [Vector method] ";
        if (t.onBorder(p))
            cout << "Point is on the border" << endl;
        else if (t.contains(p))
            cout << "Point is inside the triangle" << endl;
        else
            cout << "Point is outside the triangle" << endl;

        cout << "  [Heron method]  ";
        if (t.onBorder(p))
            cout << "Point is on the border" << endl;
        else if (t.containsHeron(p))
            cout << "Point is inside the triangle" << endl;
        else
            cout << "Point is outside the triangle" << endl;
    }

    return 0;
}