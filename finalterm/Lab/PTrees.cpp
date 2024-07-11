#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
int a[1000009];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    for (int i = 0; i < n; i++)
        a[i] += i + 2;

    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, (ll)a[i]);
    }
    cout << res;

    return 0;
}