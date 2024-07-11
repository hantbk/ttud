#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

struct Point
{
    double x, y;
    int id;
    Point(double x = 0, double y = 0, int id = 0)
    {
        this->x = x;
        this->y = y;
        this->id = id;
    }
} p[MAX];

struct Solution
{
    int id1, id2;
    double distance;
    Solution(int id1 = -1, int id2 = -1, double distance = 0)
    {
        this->id1 = id1;
        this->id2 = id2;
        this->distance = distance;
    }
};

bool cmpX(Point a, Point b)
{
    return a.x < b.x;
}

bool cmpY(Point a, Point b)
{
    return a.y < b.y;
}

double distance(Point a, Point b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

Solution solve(int first, int last){
    if(first >= last){
        Solution best = Solution(-1, -1, INF);
        return best;
    }

    int mid = (first + last) / 2;
    Solution sLeft = solve(first, mid);
    Solution sRight = solve(mid + 1, last);
    Solution best = (sLeft.distance < sRight.distance) ? sLeft : sRight;
    double d = best.distance;
    vector<Point> strip;
    for(int i = first; i <= last; i++){
        if(abs(p[i].x - p[mid].x) <= d){
            strip.push_back(p[i]);
        }
    }
    sort(strip.begin(), strip.end(), cmpY);
    for(int i = 0; i < strip.size(); i++){
        for(int j = i + 1; j < strip.size(); j++){
            if(strip[j].y - strip[i].y > d) break; 
            double tmp = distance(strip[i], strip[j]);
            if(tmp < best.distance){
                int id1 = strip[i].id;
                int id2 = strip[j].id;
                if(id1 > id2) swap(id1, id2);
                best = Solution(id1, id2, tmp);
            }
        }
    }
    return best;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> p[i].x >> p[i].y;
        p[i].id = i;
    }
    sort(p, p + N, cmpX);
    Solution sol = solve(0, N - 1);
    cout << sol.id1 << " " << sol.id2 << " " << fixed << setprecision(6) << sol.distance << endl;

    return 0;
}