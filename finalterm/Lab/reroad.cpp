#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, a[100009];

int isStart(int u)
{
    if (u == 1)
        return 1;
    return a[u] != a[u - 1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += isStart(i);

    int q;
    cin >> q;
    while (q--)
    {
        int p, c;
        cin >> p >> c;
        ans -= isStart(p);
        if (p < n)
            ans -= isStart(p + 1);
        a[p] = c;
        ans += isStart(p);
        if (p < n)
            ans += isStart(p + 1);
        cout << ans << endl;
    }

    return 0;
}