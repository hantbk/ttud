#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, t, d;
int a[MAXN], ti[MAXN];
int f[MAXN][MAXN]; // f[i][j] is the maximum amount of goods that can be carried at station i with remaining time j

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> t >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> ti[i];
    }

    memset(f, 0, sizeof(f)); // Initialize DP table to 0

    for (int i = 1; i <= n; i++)
    {
        for (int k = ti[i]; k <= t; k++)
        {
            f[i][k] = a[i]; // Carry goods at station i

            if (k < ti[i])
            {
                f[i][k] = 0;
                continue;
            }
            if (k >= ti[i])
            {
                for (int j = max(1, i - d); j <= i - 1; j++)
                {
                    f[i][k] = max(f[i][k], f[j][k - ti[i]] + a[i]);
                }
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= t; k++)
        {
            res = max(res, f[i][k]);
        }
    }
    cout << res << endl;

    return 0;
}
