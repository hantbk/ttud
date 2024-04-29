/*
    A truck is planned to arrive at some stations among the N stations.
    Station i has a[i] packages of goods ready to be loaded and t[i] minutes to load them.
    The distance between two consecutive stations that the truck arrive xi and xi+1 less than or equal to D
    and the total pickup time duration cannot exceed T minutes.

    Find the maximum number of packages the truck can load.

    Input
        Line 1: Three integers N, T, D (1 ≤ N ≤ 100, 1 ≤ T, D ≤ 1000)
        Line i+1: Two integers a[i], t[i] (1 ≤ a[i], t[i] ≤ 1000)
    Output
        The maximum number of packages the truck can load.

    Algorithm
        - Let dp[i][j] be the maximum number of packages the truck can load at station i with j minutes left.
        - dp[i][j] = a[i] if j >= t[i] and 0 otherwise.
        - dp[i][j] = max(dp[i-1][j-t[i]] + a[i], dp[i-1][j]) if i >= D.

*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 100000
#define ll long long
#define MOD 1000000007

int N, T, D; // N: số trạm, T: thời gian tối đa, D: khoảng cách tối đa
int a[1005];
int t[1005];
int dp[1005][1005]; // dp[i][j] là số lượng hàng tối đa mà xe tải có thể chở ở trạm i với thời gian còn lại j

void warehouse()
{
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= T; j++)
        {
            dp[i][j] = 0;
        }
    }

    // dp[i][j] = a[i] if j >= t[i] and 0 otherwise 
    // dp[i][j] = max(dp[i-D][j-t[i]] + a[i]) if i >= D
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= T; j++)
        {
            dp[i][j] = a[i]; // chở hàng ở trạm i

            if (j < t[i])
            {
                dp[i][j] = 0;
                continue;
            }

            // chở hàng ở trạm i
            if (i >= D)
            {
                int max_load = 0;
                for (int k = i - D; k < i; k++)
                { // chọn trạm k trong khoảng D trạm trước đó
                    max_load = max(max_load, dp[k][j - t[i]] + a[i]);
                    dp[i][j] = max_load;
                }
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= T; j++)
        {
            res = max(res, dp[i][j]);
        }
    }
    cout << res << endl;
}

// void trace()
// {
//     int i = N, j = T;
//     while (i > 0)
//     {
//         if (dp[i][j] == dp[i - 1][j])
//         {
//             i--;
//         }
//         else
//         {
//             cout << i << " ";
//             j -= t[i];
//             i--;
//         }
//     }
// }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> T >> D;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> t[i];
    }

    warehouse();
    // trace();

    return 0;
}
