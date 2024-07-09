#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

struct Point
{
    int x, y;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

struct Line{
    int a, b, c;
};

void makeLine(Point A, Point B, Line &L){
    L.a = A.y - B.y;
    L.b = B.x - A.x;
    L.c = A.x * B.y - A.y * B.x;
}

double distance(Point a, Point b)
{
    long long x = a.x - b.x;
    long long y = a.y - b.y;
    return sqrt(1LL * x * x + 1LL * y * y);
}

long long dot_product(Point O, Point A, Point B)
{
    // Tích vô hướng của OA và OB
    long long xa = A.x - O.x;
    long long ya = A.y - O.y;
    long long xb = B.x - O.x;
    long long yb = B.y - O.y;
    return 1LL * xa * xb + 1LL * ya * yb;
}

long long cross_product(Point O, Point A, Point B)
{
    // Tích có hướng của OA và OB
    long long xa = A.x - O.x;
    long long ya = A.y - O.y;
    long long xb = B.x - O.x;
    long long yb = B.y - O.y;
    return 1LL * xa * yb - 1LL * xb * ya;
}

void intersection(Line &L1, Line &L2){
    double x = (1.0 * L1.b * L2.c - 1.0 * L2.b * L1.c) / (1.0 * L1.a * L2.b - 1.0 * L2.a * L1.b);
    double y = (1.0 * L1.c * L2.a - 1.0 * L2.c * L1.a) / (1.0 * L1.a * L2.b - 1.0 * L2.a * L1.b);
    cout << "Intersection point: (" << x << ", " << y << ")\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Point O(2, 5);
    // Point A(5, 6);
    // Point B(2, 5);
    // double cos = dot_product(O, A, B) * 1.0 / (distance(O, A) * distance(O, B));
    // cout << cos << endl;

    // double sin = cross_product(O, A, B) * 1.0 / (distance(O, A) * distance(O, B));
    // cout << sin << endl;

    // Line L;
    // makeLine(A, B, L);
    // cout << L.a << "x"<< " + " << L.b << "y" << " + " << L.c << " = 0" << endl;

    Point A(3,1);
    Point B(6,4);
    Point C(2,5);
    Point D(7,0);
    Line LAB;
    Line LCD;
    makeLine(A, B, LAB);
    makeLine(C, D, LCD);
    intersection(LAB, LCD);

    return 0;
}