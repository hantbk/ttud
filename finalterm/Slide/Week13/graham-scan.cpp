// Graham's Scan Algorithm
// Tìm bao lồi của một tập hợp các điểm trong mặt phẳng là một đa giác lồi nhỏ nhất chứa tất cả các điểm đó.
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

struct Point
{
    int x, y;
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

Point P[1001];
int n;
vector<Point> ConvexHull;

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        P[i] = Point(x, y);
    }
}

long long dist2(Point A, Point B)
{
    long long x = A.x - B.x;
    long long y = A.y - B.y;
    return 1LL * x * x + 1LL * y * y;
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

// So sánh 2 điểm A và B so với điểm gốc P[0] theo thứ tự ngược chiều kim đồng hồ
bool compare(Point A, Point B)
{
    long long cp = cross_product(P[0], A, B);
    if (cp == 0)
        return dist2(P[0], A) < dist2(P[0], B);
    return cp > 0;
}

int ccw(Point A, Point B, Point C)
{
    long long cp = cross_product(A, B, C);
    if (cp == 0)
        return 0;
    return cp > 0 ? 1 : -1;
}

void grahamScan()
{
    // Tìm điểm gốc tọa độ
    int pos = 0;
    for (int i = 1; i < n; i++)
    {
        if (P[i].y < P[pos].y || (P[i].y == P[pos].y && P[i].x < P[pos].x))
        {
            pos = i;
        }
    }
    swap(P[0], P[pos]); // Chọn điểm có hoành độ nhỏ nhất làm gốc tọa độ
    sort(P + 1, P + n, compare);
    ConvexHull.push_back(P[0]);
    ConvexHull.push_back(P[1]);
    for (int i = 2; i < n; i++)
    {
        while (ConvexHull.size() > 1 && ccw(ConvexHull[ConvexHull.size() - 2], ConvexHull[ConvexHull.size() - 1], P[i]) <= 0)
        {
            ConvexHull.pop_back();
        }
        ConvexHull.push_back(P[i]);
    }

    cout<<ConvexHull.size()<<"\n";

    for (int i = 0; i < ConvexHull.size(); i++)
    {
        cout << "(" << ConvexHull[i].x << ", " << ConvexHull[i].y << ")\n";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    grahamScan();

    return 0;
}