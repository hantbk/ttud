#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

struct Block
{
    int x, y, z;
};

int n;
Block a[1009];
int maxh[1009];

void input()
{
    cin >> n;
    if (n == 0)
        exit(0);
    int x, y, z;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y >> z;
        a[3 * i - 2].x = x;
        a[3 * i - 2].y = y;
        a[3 * i - 2].z = z;
        a[3 * i - 1].x = y;
        a[3 * i - 1].y = z;
        a[3 * i - 1].z = x;
        a[3 * i].x = z;
        a[3 * i].y = x;
        a[3 * i].z = y;
    }
    for (int i = 0; i < 100; i++)
    {
        maxh[i] = 0;
    }
}

int dp(int i)
{
    if (maxh[i] != 0)
        return maxh[i];
    maxh[i] = a[i].z;
    for (int j = 1; j <= 3 * n; j++)
    {
        if (a[i].x < a[j].x && a[i].y < a[j].y ||
            a[i].x < a[j].y && a[i].y < a[j].x)
        {
            maxh[i] = max(maxh[i], a[i].z + dp(j));
        }
    }
    return maxh[i];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cnt = 1;
    while (1)
    {
        int res = 0;
        input();
        for (int i = 1; i <= 3 * n; i++)
        {
            res = max(res, dp(i));
        }
        cout << "Case " << cnt++ << ": maximum height = " << res << endl;
    }

    return 0;
}