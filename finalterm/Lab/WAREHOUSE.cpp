#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int N, T, D;
int a[1009];
int t[1009];
int ans;
int dp[1009][1009]; // dp[i][k] là số hàng tối đa thu được khi xét các nhà kho từ 1...i và thời gian lấy hàng không quá k

void qhd()
{
    for (int i = 1; i <= N; i++)
    {
        for (int k = t[i]; k <= T; k++)
        {
            for (int j = i - 1; j >= max(0, i - D); j--)
            {
                dp[i][k] = max(dp[i][k], dp[j][k - t[i]] + a[i]);
            }
            ans = max(ans, dp[i][k]);
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> T >> D;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = 1; i <= N; i++)
        cin >> t[i];
    qhd();

    return 0;
}