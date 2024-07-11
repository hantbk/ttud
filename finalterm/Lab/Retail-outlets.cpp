#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000007

int N, M;
int a[109];
int dp[109][1009]; // dp[i][j] = number of ways to make sum j using first i elements

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }

    dp[0][0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = a[i]; j <= M; j++)
        {
            for (int k = j - a[i]; k >= 0; k -= a[i])
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }

    cout << dp[N][M] << endl;

    return 0;
}