/*
    O cong vien thanh pho co 1 buc tuong
    Co 2 loai gach lat: 1x2 va 2x2
    Nhiem vu: Lat day gach 2xN
    Tim so cach lat gach
    f(n) la so cach lat gach 2xN
    f(0) = 1
    f(1) = 1
    f(n) = f(n-1) + 2*f(n-2) voi n >= 2 
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 100000
#define ll long long
#define MOD 1000000007

int n, f[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] + 2 * f[i - 2];
    }
    cout<<f[n];

    return 0;
}