// https://oj.vnoi.info/problem/nklineup
// RMQ tim min hoac max trong doan tu L -> R dung sparse table
// F: Min trong doan [L, R]
// G: Max trong doan [l, R]
#include <bits/stdc++.h>
using namespace std;
#define maxn 1000000

int n, a[maxn], f[maxn][22], g[maxn][22];

int getMin(int l, int r)
{

    int k = log2(r - l + 1);
    return min(f[1][k], f[r - (1 << k) + 1][k]);
}

int getMax(int l, int r)
{
    int k = log2(r - l + 1);
    return max(g[1][k], g[r - (1 << k) + 1][k]);
}

int main()
{
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i][0] = g[i][0] = a[i];
    }
    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            g[i][j] = max(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << getMax(l, r) - getMin(l, r) << "\n";
    }
    return 0;
}