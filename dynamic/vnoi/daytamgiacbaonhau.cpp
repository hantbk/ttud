#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

struct Point {
    int x, y;
};

struct Triangle {
    Point a, b, c;
    double area() {
        // S = 1/2 * |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)| 
        return abs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0);
    }
};

int n;
Triangle a[MAX];
int F[MAX]; // F[i] la do dai day tam giac dai nhat ket thuc tai tam giac thu i
int maxLength = 1;

bool pointInTriangle(Point p, Triangle t) {
    // Tinh dien tich 3 tam giac con
    double S = t.area();
    double S1 = Triangle{p, t.b, t.c}.area();
    double S2 = Triangle{t.a, p, t.c}.area();
    double S3 = Triangle{t.a, t.b, p}.area();
    return S == S1 + S2 + S3;
}

// Kiem tra tam giac b co nam trong tam giac a khong
bool contain(Triangle a, Triangle b) {
    return pointInTriangle(b.a, a) && pointInTriangle(b.b, a) && pointInTriangle(b.c, a);
}

bool cmp(Triangle a, Triangle b) {
    return a.area() < b.area();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>a[i].a.x>>a[i].a.y>>a[i].b.x>>a[i].b.y>>a[i].c.x>>a[i].c.y;
    }

    sort(a,a+n,cmp);

    for(int i=0; i<n; i++) F[i] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(contain(a[i],a[j])){
                F[i] = max(F[i],F[j]+1);
            }
        }
        maxLength = max(maxLength,F[i]);
    }
    
    cout<<maxLength<<endl;

    return 0;
}