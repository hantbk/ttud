#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1009
#define ll long long

int n, M;
int m[MAX], v[MAX]; // m: khối lượng, v: giá trị
int ans;
int X[MAX];
int sumM = 0, sumV = 0;

void Try(int k)
{
    if (sumM > M)
        return;

    if (k > n)
    {
        ans = max(ans, sumV);
        return;
    }

    for (int i = 0; i <= 1; i++)
    {
        X[k] = i;
        sumM += m[k] * X[k];
        sumV += v[k] * X[k];
        Try(k + 1);
        sumM -= m[k] * X[k];
        sumV -= v[k] * X[k];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> M;
    for (int i = 1; i <= n; i++)
        cin >> m[i] >> v[i];

    ans = 0;

    Try(1);

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define MAX 1009
// #define INF 1e9
// #define ll long long

// int n, M;
// int m[MAX], v[MAX]; // m: khối lượng, v: giá trị
// int dp[MAX][MAX]; // dp[i][j] là giá trị lớn nhất có thể đạt được với i món đồ và khối lượng tối đa j

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> n >> M;
//     for (int i = 1; i <= n; i++) {
//         cin >> m[i] >> v[i];
//     }

//     for (int i = 0; i <= n; i++) {
//         for (int j = 0; j <= M; j++) {
//             dp[i][j] = 0;
//         }
//     }

//     for (int i = 1; i <= n; i++) {
//         for (int j = 0; j <= M; j++) {
//             if (j >= m[i]) {
//                 dp[i][j] = max(dp[i-1][j], dp[i-1][j-m[i]] + v[i]);
//             } else {
//                 dp[i][j] = dp[i-1][j];
//             }
//         }
//     }

//     cout << dp[n][M] << endl;

//     return 0;
// }
