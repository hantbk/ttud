#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
int a[100009];
int dp[100009];

void lis()
{
    for (int i = 1; i <= n; i++)
        dp[i] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[i] == a[j] + 1)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, dp[i]);
    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        memset(a, 0, sizeof(a));
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        lis();
    }

    return 0;
}